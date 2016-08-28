//Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
//An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root-to-leaf numbers.
//
//For example,
//
//    1
//   / \
//  2   3
//The root-to-leaf path 1->2 represents the number 12.
//The root-to-leaf path 1->3 represents the number 13.
//
//Return the sum = 12 + 13 = 25.

没啥陷阱和技巧，只要dfs即可，递归出口在叶子，不是空节点。

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
    
    void dfs(TreeNode* root, int &res, int cur) {
        if(!root) {
            return;
        }
        cur = cur*10 + root->val;
        if(!root->left&&!root->right) {
            res+=cur;
        }
        
        dfs(root->left, res, cur);
        dfs(root->right, res,cur);
        
    }

    int sumNumbers(TreeNode* root) {
        int cur = 0,res = 0;
        dfs(root,res,cur);
        return res;
    }
};