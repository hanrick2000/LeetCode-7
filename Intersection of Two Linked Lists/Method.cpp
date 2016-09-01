//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists:
//
//A:          a1 → a2
//                   ↘
//                     c1 → c2 → c3
//                   ↗            
//B:     b1 → b2 → b3
//begin to intersect at node c1.
//
//
//Notes:
//
//If the two linked lists have no intersection at all, return null.
//The linked lists must retain their original structure after the function returns.
//You may assume there are no cycles anywhere in the entire linked structure.
//Your code should preferably run in O(n) time and use only O(1) memory.

//这题可以将两个指针从两头出发遍历，如果途中两者相等，则返回该点，否则任意一个到尾部了从另一个链表的头开始。直到再次遇到尾部。

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA, *q = headB;
        bool t = false, f = false;
        
        while(p&&q) {
            if(p==q) return p;
            p = p->next;
            q = q->next;
            if(!p &&!t) {
                p = headB;
                t = true;
            }
            
            if(!q&&!f) {
                q = headA;
                f = true;
            }
        }
        
        return NULL;
        
    }
};