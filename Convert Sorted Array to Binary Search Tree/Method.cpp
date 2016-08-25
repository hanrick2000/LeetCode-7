//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.


递归，从数组中间的点作为root, 然后中点左右两边分别递归构造作为root的左子树和右子树

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

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return sortedArrayToBSTHelper(nums,0,nums.size());
    }
};