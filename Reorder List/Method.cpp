//Given a singly linked list L: L0→L1→…→Ln-1→Ln,
//reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
//You must do this in-place without altering the nodes' values.
//
//For example,
//Given {1,2,3,4}, reorder it to {1,4,2,3}.
//
//Show Tags

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

这题的基本思路：找到链表中点，将后半部分反转，然后merge两半list。很多小细节和小bug


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!(head->next)) return head;
        
        ListNode* H = new ListNode(0), *pre = head, *p = pre->next;
        H->next = head;
        
        while(p) {
            
            pre->next = p->next;
            p->next = H->next;
            H->next = p;
            p = pre->next;
        }
        
        return H->next;
    }
    
    void interleaving(ListNode* p, ListNode* q) {
        
        ListNode* p1 = p, *q1 = q, *root = p;
        
        while(root) {
            p1 =p1->next;
            root->next = q1;
            
            root = root->next;
            
            if(!root) break;
            
            q1 = q1->next;
            root->next = p1;
            root = root->next;
        }
    }
    
    void reorderList(ListNode* head) {
        
        ListNode* H = new ListNode(0);
        H->next = head;
        ListNode* fast = H, *slow = H;
        
        while(fast) {
            
            fast = fast->next;
            if(fast) fast = fast->next;
            else break;
            slow = slow->next;
            
        }
        
        ListNode* newHead = reverseList(slow->next);
        slow->next = NULL;
        
        interleaving(head,newHead);
    }
};
