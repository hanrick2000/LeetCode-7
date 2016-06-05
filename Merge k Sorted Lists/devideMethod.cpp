//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

//写出了merge 2 lists 后就可以通过分治法做了。
//时间O(n／k*lgk) , n为所有节点数.


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* p = l1, *q = l2, *cur = new ListNode(0),*head = cur;
        
        while(p&&q) {
            if(p->val<q->val) {
                cur->next = p;  //cur串起小的节点
                cur = p;    //cur后移，都指向当前造完的链表的尾节点。
                p = p->next; //p照常后移
            }            
            else {
                cur->next = q;
                cur = q;
                q = q->next;
            }
        }
        if(p) cur->next = p;  //后面的指针一串即可
        else cur->next =q;
        
        return head->next; //head记得cur的头，cur不能算进去。
    }
    
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {  //类似于mergeSort
        
        if(start == end) return NULL;   //递归出口
        if(start == end-1) return lists[start]; //递归出口2  容易遗忘！！！！！
        
        int mid = (start + end)>>1;
        
        return mergeTwoLists(mergeKListsHelper(lists,start,mid),mergeKListsHelper(lists,mid, end));
                
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        return mergeKListsHelper(lists, 0, lists.size());
    }
};