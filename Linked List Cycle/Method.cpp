//Given a linked list, determine if it has a cycle in it.
//
//Follow up:
//Can you solve it without using extra space?


//还是用快慢指针。只不过判断他们想等时 要排除空。
    


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
    bool hasCycle(ListNode *head) {

        ListNode* fast = head, *slow = head;
        
        while(slow&&fast){
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
            else return false;
            
            if(slow == fast) return true;
            
        }
        
        return false;
        
    }
};