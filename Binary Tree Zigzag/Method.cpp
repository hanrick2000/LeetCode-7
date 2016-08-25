//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its zigzag level order traversal as:
//[
//  [3],
//  [20,9],
//  [15,7]
//]

//zigzag 需要双向队列，注意只要是按层便利，肯定是bfs变体，所以得用队列，不能用栈。用一个层变量level，每奇数层从队尾开始输出，依次将左孩子，右孩子从队首加入。偶数层从队首开始输出，依次将右孩子，左孩子从队尾加入。

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root) return {};
        
        deque<TreeNode*> myque;
        myque.push_back(root);
        
        vector<vector<int>> res;
        
        int level = 1;
        while(myque.size()) {
            
            int len = myque.size();
            vector<int> tmp;
            
            if(level&1) {  // odd number
                for(int i = 0; i < len; ++i) {
                    TreeNode* t = myque.back();
                    
                    myque.pop_back();
                    tmp.push_back(t->val);
                    
                    if(t->left) {
                        myque.push_front(t->left);
                    }
                    
                    if(t->right) {
                        myque.push_front(t->right);
                    }
                }
                
            }
            
            else { // even number
                for(int i = 0; i < len; ++i) {
                    TreeNode* t = myque.front();
                    
                    myque.pop_front();
                    tmp.push_back(t->val);
                    
                    if(t->right) {
                        myque.push_back(t->right);
                    }
                    
                    if(t->left) {
                        myque.push_back(t->left);
                    }
                }
            }
            ++level;
            res.push_back(tmp);
            
        }
        
        return res;
        
        
        
        
    }
};