//Find the sum of all left leaves in a given binary tree.
//
//Example:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

//只要检测左子树是不是叶子，是的话++e.递归进行O(n)

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

    bool isLeaf(TreeNode* root) {
        if(!root) return false;
        
        if(!root->left&&!root->right) {
            return true;
        }
        return false;
    }
    
    void sumOfLeftLeavesHelper(TreeNode* root, int &num) {
    
        if(!root) return ;
        
        if(isLeaf(root->left)) num+=root->left->val;
        
        sumOfLeftLeavesHelper(root->left, num);
        sumOfLeftLeavesHelper(root->right, num);
        return;
    }


    int sumOfLeftLeaves(TreeNode* root) {
        
        int e = 0;
        sumOfLeftLeavesHelper(root,e);
        return e;
    }
};