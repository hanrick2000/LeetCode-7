//Sort a linked list in O(n log n) time using constant space complexity.

  
//采用merge sort。先按照快慢指针把链表弄成两份，然后把左右两边递归进行，最后merge。
//T(n) = 2T(n/2) + O(n)

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

    ListNode* mergeSortedList(ListNode* l1, ListNode* l2) {
        
        ListNode* p = new ListNode(0), *q = p;
        
        while(l1&&l2) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        
        }
        
        p->next = l1?l1:l2;
        
        return q->next;
        
    }

    ListNode* sortList(ListNode* head) {
        
        if(!head||!head->next) return head;
        
        ListNode* fast = head, *slow = head;
        
        while(fast) {
            
            fast = fast->next;
            if(fast) fast = fast->next;
            if(fast) slow = slow->next;
            
        }
        
        fast = slow->next;
        slow->next = NULL;
        return mergeSortedList(sortList(head),sortList(fast));
        
        
    }
};
