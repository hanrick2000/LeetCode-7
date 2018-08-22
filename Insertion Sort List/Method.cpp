//Sort a linked list using insertion sort.

控制一个指针p从头到尾，循环内控制一个指针q从头到p,如果q的值大于p的值，就将p插入到q之前.


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
    ListNode* insertionSortList(ListNode* head) {
        
        if(!head) return head;
        
        ListNode* p = head->next,*ppre = head,*H = new ListNode(0);
        H->next = head;
        while(p) {
            ListNode* q = H;
            bool change = false;
            while(q->next!=p) {
                if(q->next->val>p->val) {
                    ppre->next = p->next;
                    p->next = q->next;
                    q->next = p;
                    change = true;
                    break;
                }
                
                q = q->next;
            }
            
            if(!change) {  //没该过，ppre正好在p前面,改过它取代了p的位置。
                ppre = p;                
            }
                
            p = ppre->next;
            
        }
        
        return H->next;
        
    }
    
    优化版本：记录当前最大值，如果p值大于最大值就可以直接后移指针，不用每次都从头开始找。
    
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        
        ListNode* H = new ListNode(0), *p = head->next, *ppre = head;
        H->next = head;
        
        int curMax = head->val;
        
        while(p) {
            if(p->val >= curMax) {
                curMax = p->val;
                ppre = p;
                p = p->next;
                continue;
            }
            
            ListNode* pre = H, *q = pre->next;
            while(q->val < p->val) {  
                q = q->next;  
                pre = pre->next;
            }
            //找到第一个点q值大于p. 
            ppre->next = p->next;
            p->next = q;
            pre->next = p;
            p = ppre->next;
        }
        
        p = H->next;
        delete H;
        return p;
    }
    
};