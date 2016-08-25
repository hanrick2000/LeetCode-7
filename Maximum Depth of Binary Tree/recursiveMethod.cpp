//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
//Show Company Tags
//Show Tags
//Show Similar Problems

//递归（dfs) 深度 等于1+max(左子树深度，右子树深度)。

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
    
    

    int maxDepth(TreeNode* root) {
        
        return root?max(maxDepth(root->left)+1,maxDepth(root->right)+1):0;
        
    }
};