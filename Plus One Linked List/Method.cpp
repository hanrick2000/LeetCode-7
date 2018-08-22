//Given a non-negative number represented as a singly linked list of digits, plus one to the number.
//
//The digits are stored such that the most significant digit is at the head of the list.
//
//Example:
//Input:
//1->2->3
//
//Output:
//1->2->4

就用栈，O（n） 空间.放Node比较好.稍微省一点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        
        stack<ListNode*> mystack;
        
        ListNode* p = head;
        
        while(p) {
            mystack.push(p);
            p = p->next;
        }
        
        int carry = 1;
        
        while(mystack.size()&&carry) {
            p = mystack.top();
            p->val += carry;
            
            carry = p->val/10;
            p->val %=10;

            mystack.pop();
        }
        
        if(carry) {
            p = new ListNode(1);
            
            p->next = head;
            
            return p;
            
        }
        
        return head;
        
    }
    
    用递归感觉也挺直观的。
    
    bool plusOneHelper(ListNode* head) {
        if(!head) return 0;
        
        if(!head->next) {
            head->val+=1;
            head->val%=10;
            return !head->val;
        }
        
        head->val += plusOneHelper(head->next);
        bool flag = head->val == 10;
        head->val%=10;
        
        return flag;
    }

    ListNode* plusOne(ListNode* head) {

        if(plusOneHelper(head)) {
            ListNode *t = new ListNode(1);
            t->next = head;
            return t;
        }
        
        return head;
    }
};