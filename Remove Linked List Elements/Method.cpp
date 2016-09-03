//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//Return: 1 --> 2 --> 3 --> 4 --> 5

//很简单，指针p走一步看 下一步，如果是val,跳掉p->next.注意指针不能动，如果不等于指针才继续动。

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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* H = new ListNode(0), *p = H;
        
        H->next = head;
        
        while(p->next) {
            if(p->next->val == val) {
                p->next = p->next->next;
                // delete p->next;
            }
            
            else {
                p = p->next;
            }
        }
        
        return H->next;
        
    }
};