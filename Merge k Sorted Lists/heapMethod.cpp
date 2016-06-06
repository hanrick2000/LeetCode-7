//每一次都要串上值最小的节点，所以可以用一个堆来挑出，起初，先把k个头指针放入堆，每一次弹出最小的指针，放入该指针的next指针。
//时间O(nlogk) 总共n个数，而每一次heap操作要log k 。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class cmp {
public:
    bool operator () (ListNode* a, ListNode* b) {
        return a->val > b->val;       
    }
};
 
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(!lists.size()) return NULL;   //这两个可以不用，可以通过while heap.size() 去判断
        // if(lists.size()==1) return lists[0];
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> myheap; 
        
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i]) myheap.push(lists[i]);
        }
        
        ListNode* cur = new ListNode(0), *Head = cur;
        
        while(myheap.size()) {
            ListNode* tmp = myheap.top();
            cur->next = tmp;
            if(myheap.size()==1) return Head->next;     //如果只有一个节点，那么串起来就可以返回了，不必反反复复走到底再串。
            cur = tmp;
            myheap.pop();
            
            if(tmp->next) myheap.push(tmp->next);
        }
        
        return Head->next;
    }
};