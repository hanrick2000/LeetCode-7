//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.

//很简单 控制一个指针，比较这个值和下一个指针的值。也可以就用一个指针

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *pre = head, *p = pre->next;
        
        while(p) {
            if(p->val == pre->val) {
                pre->next = p->next;
                // delete(p);
            }
            else {
                pre = p;
            }
            
            p = pre->next;
        }
        
        return head;
    }
};