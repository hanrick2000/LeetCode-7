//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.
//
//Show Tags

这题就要维护两个指针big和small。遇见一个小的元素 就让添加到small，否则就添加到big, 控制两个指针big_base,small_base指向big和small的头部。最后记得big接地，small接big_base.

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* big_base = NULL, *small_base = NULL, *big = big_base, *small = small_base, *p = head;
        
        while(p) {
            if(p->val<x) {
                if(!small) {
                    small_base = p;
                }
                else {
                    small->next = p;
                }
                small = p;
            }
            
            else {
                if(!big) {
                    big_base = p;

                }
                else {
                    big->next=p;
                }
                big = p;
                
            }
            p = p->next;
        }
        
        if(big) big->next = NULL;
        if(small) small->next = big_base;
        
        return small_base?small_base:big_base;
        
    }
};