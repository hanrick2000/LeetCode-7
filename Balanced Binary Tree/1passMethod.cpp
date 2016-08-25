//Given a binary tree, determine if it is height-balanced.
//
//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//

//
//bst 定义：
//1）空树
//2）左右子树的高度差不超过1
//3）左右子树也是bst
//正常来说需要两遍自底向上的递归，要求root是否是bst,先要递归求左右子树的高度，然后再要递归求左右子树是否是bst。
//现在我们可以一遍递归，用每一个节点的val来保存当前节点的高度。这样求root是否是bst时先自顶向下递归，求到节点时向上一边返回是否是bst,一边修改节点的val.


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

    bool isBalanced(TreeNode* root) {  
        if(!root) return true;
        
        if(!isBalanced(root->left)||!isBalanced(root->right)) return false; //该步骤把左右子树下的所有节点值都填完了

        int leftLevel = root->left?root->left->val:0, rightLevel = root->right?root->right->val:0;
        
        if(abs(leftLevel-rightLevel)>1) return false;
        
        root->val = 1+max(leftLevel,rightLevel);
        
        return true;
    }
};