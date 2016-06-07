//Reverse a singly linked list.

//迭代法：我们知道，顺序迭代一个链表把每一个节点进行头插法就可以reverse，所以我们修改指针也可以这么来，只要把当前指针后的元素修改指针插到头就好。

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
};