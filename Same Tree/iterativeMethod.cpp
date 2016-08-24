同时进行两个dfs即可。空间O(n),时间o(n).

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        if(!p||!q) return false;
       
       stack<TreeNode*> Lstack, Rstack;
       
       Lstack.push(p);
       Rstack.push(q);
       
       while(Lstack.size()&&Rstack.size()) {
           TreeNode* l = Lstack.top();
           TreeNode* r = Rstack.top();
           
           Lstack.pop();
           Rstack.pop();
           
           if(l->val!=r->val) return false;
           
           if(l->right&&r->right) {
               Lstack.push(l->right);
               Rstack.push(r->right);
           }
           
           else if(l->right||r->right) {
               return false;
           }
           
           
           if(l->left&&r->left) {
               Lstack.push(l->left);
               Rstack.push(r->left);
           }
           
           else if(l->left||r->left) {
               return false;
           }
        }
        
        return true;
    }
};