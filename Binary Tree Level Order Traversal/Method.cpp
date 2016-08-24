//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its level order traversal as:
//[
//  [3],
//  [9,20],
//  [15,7]
//]

//很简单的bfs,别忘记pop()!

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root) return {};
        
        queue<TreeNode*> myque;
        myque.push(root);
        vector<vector<int>> res;
        TreeNode* l;
        
        while(myque.size()) {
            
            int len = myque.size();
            vector<int> tmp;
            for(int i = 0; i < len; ++i) {
                l = myque.front();
                myque.pop();
                tmp.push_back(l->val);
                if(l->left) myque.push(l->left);
                if(l->right) myque.push(l->right);
            }
            res.push_back(tmp);
        }
        
        return res;
        
    }
};