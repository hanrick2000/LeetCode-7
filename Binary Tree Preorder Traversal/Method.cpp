//Given a binary tree, return the preorder traversal of its nodes' values.
//
//For example:
//Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
//return [1,2,3].
//
//Note: Recursive solution is trivial, could you do it iteratively?
//
//Show Tags
//Show Similar Problems
//
//记住相当于是dfs,得用栈，别搞错了！！


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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        TreeNode* tmp;
        stack<TreeNode*> mystack;
        mystack.push(root);
        vector<int> res;
        
        while(mystack.size()) {
            tmp = mystack.top();
            mystack.pop();
            res.push_back(tmp->val);

            
            if(tmp->right) {
                mystack.push(tmp->right);
            }
            
            if(tmp->left) {
                mystack.push(tmp->left);
            }
            
        }
        
        return res;
        
    }
};