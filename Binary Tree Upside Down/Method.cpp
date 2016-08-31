//Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
//
//For example:
//Given a binary tree {1,2,3,4,5},
//    1
//   / \
//  2   3
// / \
//4   5
//return the root of the binary tree [4,5,2,#,#,3,1].
//   4
//  / \
// 5   2
//    / \
//   3   1  


//这棵树的翻转规律是，递归对左子树进行，然后左子树的根节点下的最右节点右子树连上root, 左子树连上根的右子树。记得把连上后root, 左右子树清空。


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
    TreeNode* findRight(TreeNode* root) {
        while(root->right) {
            root = root->right;
        }
        return root;
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root||!root->left)  return root;
        
        TreeNode* newRoot = upsideDownBinaryTree(root->left);
        
        TreeNode* newRight = findRight(newRoot);
        
        newRight->left = root->right;
        newRight->right = root;
        root->left = NULL;
        root->right = NULL;
        return newRoot;
    }
};