//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//But the following [1,2,2,null,3,null,3] is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3
//Note:
//Bonus points if you could solve it both recursively and iteratively.

//递归法，判断左右两子树是否是“镜像”， 具体递归做法和same tree极像。

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
    
    bool isMirror(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        if(!p||!q||p->val!=q->val) return false;
        
        return isMirror(p->left,q->right)&&isMirror(p->right,q->left);
        
    }
    
    bool isSymmetric(TreeNode* root) {
       
       if(!root) return true;
       
       return isMirror(root->left,root->right);
        
        
    }
};