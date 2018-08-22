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
    
    
    void deleteNode(ListNode* node) {
        
        while(node->next) {
            
            node->val = node->next->val;
            
            if(!node->next->next) {
                delete node->next;
                node->next = NULL;
                break;
            }
            
            node = node->next;
        }
        
        
    }
    
    void deleteNode(ListNode* node) {
        
        ListNode* p = node->next;

        node->val = p->val;
        node->next = p->next;
        
        delete p;
        p = NULL;
        
    }
};

Some things to consider. This method could pose potential problems. For instance, let’s consider we have a linked list A -> B -> C -> D and we are given a pointer to B to delete it. Theoretically, you would expect B to be deleted and all pointers which were pointing to B to become invalid. However, if we use this function to delete B, all pointers which were pointing to B will still be valid. Furthermore, node B now will contain the value C and node C will be invalid. Any previous pointers to C will become invalid, which may not be expected behavior in general. This is not a problem if there are no external links to any of the items in the linked list. But this would definitely be something you should consider asking your interviewer to show your thinking process.