//Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
//
//Example:
//Given binary tree 
//          1
//         / \
//        2   3
//       / \     
//      4   5    
//Returns [4, 5, 3], [2], [1].
//
//Explanation:
//1. Removing the leaves [4, 5, 3] would result in this tree:
//
//          1
//         / 
//        2          
//2. Now removing the leaf [2] would result in this tree:
//
//          1          
//3. Now removing the leaf [1] would result in the empty tree:
//
//          []         
//Returns [4, 5, 3], [2], [1].


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//这题思路还是很好想的，首先dfs递归找到叶子，把叶子的值放进去，然后返回时，如果是叶子返回true，否则返回false。 如果返回true就剪枝，把相应的孩子设为空。然后对树不停的进行，直到节点为空。要引入一个辅助节点来做

class Solution {
public:

    bool findLeavesHelper(TreeNode* root, vector<int> &res) {
        
        if(!root) return false;
        
        if(!root->left&&!root->right) {
            res.push_back(root->val);
            return true;
        }
        
        if(findLeavesHelper(root->left,res)) root->left = NULL;
        if(findLeavesHelper(root->right,res)) root->right = NULL;
        
        return false;
        
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> rst;
        
        TreeNode* T = new TreeNode(0); 
        T->left = root;
        
        while(T->left) {
            vector<int> res;
            findLeavesHelper(T,res);
            rst.push_back(res);
        }

        return rst;
    }
};