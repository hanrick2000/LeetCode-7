//Given a binary tree, return all root-to-leaf paths.
//
//For example, given the following binary tree:
//
//   1
// /   \
//2     3
// \
//  5
//All root-to-leaf paths are:
//
//["1->2->5", "1->3"]


//用递归法比较好写，只要遍历完一遍数就出来了。

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

    void dfs(TreeNode* root, vector<string> &res, string cur) {
        if(!root) return;
        
        cur += cur == "" ?to_string(root->val): "->" + to_string(root->val);
        
        if(!root->left&&!root->right) {
            res.push_back(cur);
            return;
        }
        
        dfs(root->left, res, cur);
        dfs(root->right, res, cur);
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        
        vector<string> res;
        string cur;
        dfs(root, res, cur);
        
        return res;
        
    }
};