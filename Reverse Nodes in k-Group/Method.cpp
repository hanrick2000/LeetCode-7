//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5

//要熟练使用reverse link list. 然后每找到一组长度就要reverse。注意循环跳出的条件 以及指针的更新。

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k == 1||!head) return head;
        
        ListNode* H = new ListNode(0);
        H->next = head;
        ListNode*p1 = H, *pre=p1->next, *p=pre->next, *post=p1;
        
        while(1) {

            for(int i = 0; i < k; ++i) {
                post = post->next;
                if(!post) return H->next;  // 表示这一轮下来不到k个节点，不用倒置
            }

            while(1) {
                pre->next = p->next;    //头插，交换指针，可以看清楚 每次右值被保存后，下一个表达式会将该右值放到左值进行覆盖
                p->next = p1->next;
                p1->next = p;
                if(p==post) break;  //表示这是最后一个元素，且头插完毕
                p = pre->next;
            }

            p1 = post ＝ pre;   //更新 所有的指针
            pre=p1->next;
            if(!pre) return H->next;
            p=pre->next;
        }
    
    }
};