//Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
//
//You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
//
//Example:
//Given 1->2->3->4->5->NULL,
//return 1->3->5->2->4->NULL.
//
//Note:
//The relative order inside both the even and odd groups should remain as it was in the input. 
//The first node is considered odd, the second node even and so on ...

//仔细一点不会出错，奇的头负责链接所有奇数点，偶的头负责链接所有偶数点，最后记住奇数尾要连上偶数头，偶数尾可能要连上空。

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next) return head;
        
        ListNode* odd = head, *even = head->next, *cur = even->next, *p = even;
        
        while(cur) {
            
            odd->next = cur;
            odd = cur;
            
            cur = cur->next;
        
            p->next = cur;
            
            if(!cur) break;
            
            p = cur;
            cur = cur->next;
        }
    
        odd ->next = even;
        
        return head;    
    }
};

