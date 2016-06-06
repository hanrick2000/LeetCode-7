//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


//修改指针的练习， 很明显，两个两个一组，调换p1,p2次序要修改三次指针，p1前（得用pre记录）,p1和p2之间,p2后面。然后每一次三个指针向后移两个位置。

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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head||!(head->next)) return head;
        
        ListNode* H = new ListNode(0), *p1=head,*p2, *pre = H;
        H->next = head;
        
        while(p1&&p1->next) {
            p2 = p1->next;
            p1->next = p2->next;
            pre->next = p2;
            p2->next = p1;
            pre = p1;
            p1 = pre->next;
        }
        
        return H->next;
        
    }
};