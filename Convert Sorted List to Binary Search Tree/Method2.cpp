//该方法把链表变为数组。用的O(n)的时间和O(n)的空间。

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
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {
        if(start == end) return NULL;
        // if(start + 1 == end) return new TreeNode(nums[start]);
        
        int mid = (start + end)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = sortedArrayToBSTHelper(nums,start,mid);
        root->right = sortedArrayToBSTHelper(nums,mid+1,end);
        
        return root;
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode* p = head;
        
        while(p) {
            nums.push_back(p->val);
            p = p->next;
        }
        
        return sortedArrayToBSTHelper(nums,0,nums.size());
        
    }
};