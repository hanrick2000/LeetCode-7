//Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
//For example:
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note:
//Given m, n satisfy the following condition:
//1 ≤ m ≤ n ≤ length of list.

//这题和reverse link list I 核心一样，不过 得将上次的H换成现在的p1，即在m前的那个位置。while循环用n来控制。 


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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if(m==n) return head;
        
        ListNode* H = new ListNode(0), *p1 = H, *pre,*p;
        H->next = head;
        
        int q = 0;
        
        while(++q<m) p1 = p1->next;
        
        pre = p1->next, p = pre->next;
        
        while(q++<n) {
            pre->next = p->next;
            p->next = p1->next;
            p1->next = p;
            p = pre->next;
        }
        return H->next;
    }
};