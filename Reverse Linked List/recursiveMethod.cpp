//递归法：  如下图 要求 reverseList(head)
//   head   temp
//     1     2     3..... n
//
//   假设求得了reverse(temp): 链表是这样，
//   head   rst         temp
//     1     n    n-1 ... 2
//这时只要把head放到temp->next,再把head->next置空，返回新头节点rst即可。注意递归出口。

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

    ListNode* reverseList(ListNode* head) {
        
        if(!head||!(head->next)) return head;
        
        ListNode* temp = head->next, *rst = reverseList(temp);;
        
        head->next = NULL;
        temp ->next = head;
        
        return rst;
        
    }
};