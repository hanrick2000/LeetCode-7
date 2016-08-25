//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its bottom-up level order traversal as:
//[
//  [15,7],
//  [9,20],
//  [3]
//]

//只要先把层数先求出来，然后就可以根据层数来找到下标，然后赋值。 用进阶功能可以使用reverse函数。如果用push_front会使用o(n^2)的时间。


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

    
    int maxLevel(TreeNode* root) {
        return root?1+max(maxLevel(root->left),maxLevel(root->right)) : 0;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        int level = maxLevel(root);
        vector<vector<int>> res(level);
        
        queue<TreeNode*> myque;
        myque.push(root);
        
        for(int j = level-1; j>=0; --j) {
            int len = myque.size();
            
            vector<int> tmp;
            
            for(int i = 0; i < len; ++i) {
                TreeNode* t = myque.front();
                myque.pop();
                
                tmp.push_back(t->val);
                
                if(t->left) {
                    myque.push(t->left);
                }
                
                if(t->right) {
                    myque.push(t->right);
                }
            }
            res[j] = tmp;
        }
        
        
        return res;
    }
};