//Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
//For example:
//Given the following binary tree,
//   1            <---
// /   \
//2     3         <---
// \     \
//  5     4       <---
//You should return [1, 3, 4].

只要bfs,每一层时多加一句。。把最右的一个节点放入结果。

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
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root) return {};
        
        queue<TreeNode*> myque;
        
        myque.push(root);
        vector<int> res;
        
        while(myque.size()) {
            
            int len = myque.size();
            
            for(int i = 0; i < len; ++i) {
                TreeNode* tmp = myque.front();
                myque.pop();
                if(tmp->left) {
                    myque.push(tmp->left);
                }
                if(tmp->right) {
                    myque.push(tmp->right);
                }
                
                if(i == len-1) {
                    res.push_back(tmp->val);
                }
            }
        }
        
        return res;
        
    }
};