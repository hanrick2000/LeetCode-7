//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//   Given linked list: 1->2->3->4->5, and n = 2.
//
//   After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//Given n will always be valid.
//Try to do this in one pass.

//巧妙的方法，要想一遍扫描就想知道倒数第n个节点的位置，我们可以类比速度差的原理，现在速度差是n个节点，那么我们可以先让一台指针走n个节点，然后在让另一个指针从头出发，这样俩指针距离始终差n。于是当第一台指针到结尾时，第二个指针真好驻足在倒数第n个节点处。细节请自行想清楚，至于边界条件，考虑删除倒数第1个和n个的情形。

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* p = head, *H = new ListNode(0), *q=H;
        H->next = head;
        
        for(int i = 0; i < n; ++i) {
            p = p->next;
        }
        
        while(p) {
            p=p->next;
            q=q->next;
        }
        
        ListNode* temp =  q->next;
        q->next = temp->next;
        delete temp;
        return H->next;
        
    }
};