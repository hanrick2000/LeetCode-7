//Given a singly linked list, determine if it is a palindrome.
//
//Follow up:
//Could you do it in O(n) time and O(1) space?

这题follow up做法是快慢指针找到中点，然后翻转后面的linkedlist, 然后从一个从起点，另一个从中点开始一个一个比较。

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

    
    ListNode* reverseLinkList(ListNode* head) {
        
        if(!head) return NULL;
        
        ListNode* H = new ListNode(0), *p = head->next, *pre = head;
        H->next = head;
        
        while(p) {
            
            pre->next = p->next; 
            p->next=H->next;
            H->next = p;
            p = pre->next;
            
        }
        
        return H->next;
        
    }


    bool isPalindrome(ListNode* head) {
        
        if(!head) return true;
        
        ListNode *slow = head, *fast = head;
        
        while(fast) {

            fast = fast->next;
            if(fast) {
                fast = fast->next;
            }
            else {
                break;
            }
            
            if(!fast) break;
            slow = slow->next;
        }
        
        slow->next = reverseLinkList(slow->next);
        
        slow = slow->next;
        fast = head;
        
        
        while(slow) {
            if(fast->val!=slow->val) return false;
            
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
        
    }
};