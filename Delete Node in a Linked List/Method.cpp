//Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
//
//Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

//只要不断把后面的值赋值给当前的node就可以了。删除时把最后一个node给删了，指针走到倒数第二个。

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
    void deleteNode(ListNode* node) {
        
        while(node->next) {
            node->val = node->next->val;
            
            if(!node->next->next) {
                node->next = NULL;
                return;
            }
            
            node = node->next;
        }
    }
};