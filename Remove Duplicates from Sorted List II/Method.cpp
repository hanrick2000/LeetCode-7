//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.
//
//这题要想写的无bug很难。每次我们遇到一个新的值，不论重复与否，我们都要纪录该值出现的第一个位置，如果我们通过后来的遍历计数，发现该值重复，那么我们就绕过这个值，否则就串上这个值。 串的节点用pre来纪录，所以我们还得先开辟一个线头H。
//    
//尤其要注意  1,1,2 和 1,2,2这俩例子。


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        
        ListNode *H = new ListNode(0), *pre = H, *p = head->next,*p1 = head;
        int count = 1;
        
        while(p) {
            if(p->val == p1->val) {
                ++count;
            }
            else {
                if(count == 1) {
                    pre->next = p1;
                    pre = p1;
                }
                p1 = p;
                count = 1;
            }
            p = p->next;
        }
        pre->next = count>1?NULL:p1;   //好好琢磨  1,1,2 和 1,2,2这两个例子  体会这句话
        
        
        return H->next;
    }
    
    严格要求，必须把多余的元素也得释放。。那么我们假设一个上一个节点出现的值t，用一个指针p指向当时不可能重复的最后一个节点 。head 遍历 如果head值和上一个出现的值一样，说明p后面的节点要删掉了，删掉这个节点 head 继续设为这个点，下次循环还要再删，如果  值不一样，我们修改t，然后考虑这个点会不会是重复节点（peek一下下次），如果值一样，说明这个节点不可能是不重复的，否则可以让p等于这个head.
    
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head) return head;
        
        ListNode* H = new ListNode(0), *p = H;
        
        H->next = head;
        
        int t = head->val-1;

        while(head) {
            if(head->val == t) {
                
                ListNode *tmp = p->next;
                
                p->next = tmp->next;
                delete tmp;
                head = p->next;
            }  else {
                
                t = head->val;
                if(head->next&&head->next->val != t) p = head;
                head = head->next;
            }
        }
        
        return H->next;
        
    }
};