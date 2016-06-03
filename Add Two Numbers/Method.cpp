//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution.
//
//Example:
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].
//UPDATE (2016/2/13):
//The return format had been changed to zero-based indices. Please read the above updated description carefully.


//本方法是 in-place做法， 原地基础上修改l1返回l1. 指针定义如下：
//  p迭代链表l1，ppre是q前驱.当l1迭代完后，如果l2还有剩余，继续用l1迭代.
//  l1*    ppre p    
//   |     |    |
//   1->2->3->NULL
//  l2*         q   
//   |          |
//   1->2->3->4000
//   
//  时间O(n) 空间 O(1)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1) return l2;    // l1空  返回l2
        
        ListNode* p = l1, *q = l2, *ppre = p;
        
        int flag = 0;
        
        while(p&&q) {
            
            int temp = flag + p->val+q->val;
            flag = temp/10;
            p->val = temp%10;
            ppre = p;           //记录ppre 在p前驱
            p=p->next;
            q=q->next;
        }
        
        if(!p) {        //如果l1 访问完了就把前面那段和 l2后面部分接起来,p从l2继续走。否则表明l1更长，啥也不用做直接进入下面循环
            ppre->next = q;
            p = q;
        }
  
        while(p) {   //继续计算原来剩余的l2部分
            int temp = flag + p->val;
            flag = temp/10;
            p->val = temp%10;
            ppre = p;
            p = p->next;
        }
        
        if(flag) {
            ppre ->next = new ListNode(1);
        }
        
        return l1;
        
    }
};