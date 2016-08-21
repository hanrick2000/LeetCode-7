//Given a binary tree, determine if it is a valid binary search tree (BST).
//
//Assume a BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
//Example 1:
//    2
//   / \
//  1   3
//Binary tree [2,1,3], return true.
//Example 2:
//    1
//   / \
//  2   3
//Binary tree [1,2,3], return false.
//

//很简单用递归，但是不仅左右两树都是bst, 根节点的数值也要小于右子树最小值（或者右子树为空树），大于左子树的最大值（或者左子树是空树）。特别的，空树也是bst。


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

    int maxi(TreeNode* root) {
        while(root->right) {
            root = root->right;
        }
        
        return root->val;
    }
    
    int mini(TreeNode* root) {
        while(root->left) {
            root = root->left;
        }
        
        return root->val;
    }
    

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        if(!isValidBST(root->left)) return false;
        if(!isValidBST(root->right)) return false;
        
        return (!root->left||maxi(root->left)<root->val) && (!root->right||mini(root->right)>root->val);
               
    }
};