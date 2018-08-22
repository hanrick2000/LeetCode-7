//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

//归并两个有序链表，此方法要求用指针将这两个链表串起来，不能新建链表。思路是，用一个cur指针表示正在串的连标的结尾指针，同时p和q迭代两链表，小的那个节点被cur串起来。开始用head记住cur的头即可，因为cur要随时移动。


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
    
    简洁版。循环其实每次就是 cur->next = l1,l2小的那个。我们用一个指针引用small 引用它。 然后small = small->next即可 记住一定要引用，这样small = small->next 才能真正让它指的 l1,l2 移动，否则l1,l2是不会动的。
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* H = new ListNode(0), *cur = H;
        
        while(l1&&l2) {
            ListNode*& small = l1->val < l2->val? l1 : l2;
            cur->next = small;
            small = small->next;
            cur = cur->next;
        }
        
        cur -> next = l1?l1:l2;
        
        cur = H->next;
        delete H;  // 防止内存溢出
        //H = NULL; 原本这是为了防止重复delete H，不过函数销毁后这个H会自动回收，因为H是一个变量在系统栈里
        
        return cur;
    }
};