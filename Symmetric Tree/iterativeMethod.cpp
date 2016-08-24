//用标准的迭代dfs的方式进行书写。可以从左边dfs和右边dfs同时比较。用时O(n),空间最坏O(n）。
    
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
    
    bool isSymmetric(TreeNode* root) {
       
       if(!root) return true;
       
       stack<TreeNode*> Lstack, Rstack;
       
       Lstack.push(root);
       Rstack.push(root);
       
       while(Lstack.size()&&Rstack.size()) {
           TreeNode* l = Lstack.top();
           TreeNode* r = Rstack.top();
           
           Lstack.pop();
           Rstack.pop();
           
           if(l->val!=r->val) return false;
           
           if(l->right&&r->left) {
               Lstack.push(l->right);
               Rstack.push(r->left);
           }
           
           else if(l->right||r->left) {
               return false;
           }
           
           
           if(l->left&&r->right) {
               Lstack.push(l->left);
               Rstack.push(r->right);
           }
           
           else if(l->left||r->right) {
               return false;
           }
        }
        
        return true;
        
    }
};