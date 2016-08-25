//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

//该方法还是递归，每一次将链表从中间劈开来，中点作为root,左边是递归链表，右边是递归链表，时间T(n) = 2*T(n/2) + O(n)
//时间nlogn. 空间O(1). 递归运用的是堆空间。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(!head) return NULL;
        
        ListNode* H = new ListNode(0), *fast = H, *slow = H, *pre;
        H->next = head;
         
        while(fast) {
            fast = fast->next;
            pre = slow;
            slow = slow->next;
            if(fast)  fast = fast->next;

        }
         
        TreeNode* root = new TreeNode(slow->val);
        pre->next = NULL;
        root->left = sortedListToBST(H->next);
        root->right = sortedListToBST(slow->next);
        
        return root;
        
    }
};