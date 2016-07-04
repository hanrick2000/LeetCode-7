//Given a list, rotate the list to the right by k places, where k is non-negative.
//
//For example:
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

//这题提醒用two pointers, 可以先让fast指针 走k步，然后slow fast 一起走，这样fast走到头后slow 可以走到拆分点。但是有一个问题，题目的k 可以大于链表的长度，所以这种情况我们还是要把整个链表都遍历一遍。求出链表长度／


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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!(head->next)||!k) return head;
        
        ListNode* slow = head, *fast = head, *res;

        int length = 0;
        
        while(fast) {
            length++;
            fast = fast->next;
        }
        
        k %= length;
        fast = head;
        
        for(int i = 0; i < k; ++i) {
            fast = fast->next;
        }
        
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = head;
        res = slow->next;
        slow->next = NULL;
        
        return res;
        
    }
};