//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
//Note: Do not modify the linked list.
//
//Follow up:
//Can you solve it without using extra space?

//也是很巧妙的一道题，先同II一样，先用快慢指针确定是否有环，否则快慢指针会在环里面的一点相遇。可以知道该点距离头节点与环的长度相等，（因为快指针速度正好是慢指针两倍，且套了一圈）  这一点很巧妙， 假设又有一个指针从头出发，慢指针和它一模一样走一圈，又回在这点相遇，这表明，这两个指针第一次相遇时的点就是环的第一节点。
//即设慢指针一开始走到第一个节点为x,停住时走了k,那么环里面走了k-x,那么这个慢指针再走x,就到了环的起点。
    
    
    

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        
        while(slow&&fast){
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
            if(!fast) return NULL;
            
            if(slow == fast) break;
            
        }
        
        fast = head;
        while(fast!=slow) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;
    }
};