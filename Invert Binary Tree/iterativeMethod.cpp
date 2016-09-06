//这题其实三种遍历方式都可以。随便默写了先序遍历。

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

    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        
        stack<TreeNode*> mystack;
        mystack.push(root);
        
        while(mystack.size()) {
            TreeNode* tmp = mystack.top();
            
            mystack.pop();
            
            swap(tmp->left,tmp->right);
            
            if(tmp->left) {
                mystack.push(tmp->left);
            }
            
            if(tmp->right) {
                mystack.push(tmp->right);
            }
            
        }
        
        return root;
    }
};