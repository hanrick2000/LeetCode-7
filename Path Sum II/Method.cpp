//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
//For example:
//Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
//return
//[
//   [5,4,11,2],
//   [5,8,4,5]
//]

//很显然还是dfs 注意回溯，要保持cur状态的一致性。

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

    void dfs(TreeNode* root, vector<vector<int>> &res, vector<int> &cur, int sum) {
        
        if(!root) return;
        
        if(!root->left&&!root->right) {
            if(sum == root->val) {
                cur.push_back(sum);
                res.push_back(cur);
                cur.pop_back();
                
            }
            return;
        }
        
        cur.push_back(root->val);
        dfs(root->left,res,cur,sum-root->val);

        dfs(root->right,res,cur,sum-root->val);
        cur.pop_back();
        
        return;
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> res;
        vector<int> cur;
        
        dfs(root,res,cur,sum);
        return res;
        
    }
};
