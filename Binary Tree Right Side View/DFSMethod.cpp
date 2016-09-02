//先求出树的深度。然后，dfs,用一个变量depth,记录这是第几层，然后覆盖值给结果，最后被覆盖的总是最右边的。

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

    int depth(TreeNode* root) {
        
        return root? 1+max(depth(root->left),depth(root->right)) : 0;
    }
    
    void dfs(TreeNode* root, int depth, vector<int> &res) {
        if(!root) return;
        
        if(root->left) {
            dfs(root->left, depth+1,res);
        }
        
        res[depth] = root->val;
        
        if(root->right) {
            dfs(root->right, depth+1, res);
        }
        
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res(depth(root));
        dfs(root,0,res);
        
        return res;
    }
};