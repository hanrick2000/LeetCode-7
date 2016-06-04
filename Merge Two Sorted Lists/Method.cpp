//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

//归并两个有序链表，此方法要求用指针将这两个链表串起来，不能新建链表。思路是，用一个cur指针表示正在串的连标的结尾指针，同时p和q迭代两链表，小的那个节点被cur串起来。开始用head记住cur的头即可，因为cur要随时移动。


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1) return l2;
        if(!l2) return l1;
        
        
        ListNode* p = l1, *q = l2, *cur = new ListNode(0),*head = cur;
        
        while(p&&q) {
            if(p->val<q->val) {
                cur->next = p;  //cur串起小的节点
                cur = p;    //cur后移，都指向当前造完的链表的尾节点。
                p = p->next; //p照常后移
            }
            
            else {
                cur->next = q;
                cur = q;
                q = q->next;
            }
        }
        
        if(p) cur->next = p;  //后面的指针一串即可
        else cur->next =q;
        
        return head->next; //head记得cur的头，cur不能算进去。
    }
};