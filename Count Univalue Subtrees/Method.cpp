//Given a binary tree, count the number of uni-value subtrees.
//
//A Uni-value subtree means all nodes of the subtree have the same value.
//
//For example:
//Given binary tree,
//              5
//             / \
//            1   5
//           / \   \
//          5   5   5
//return 4.

//递归方式判断，  写一个helper函数返回是子树是不是univalue, 然后在里面更改result,主函数中返回这个result。

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
    bool countUnivalSubtreesHelper(TreeNode* root, int &res) {
        if(!root) return true;
        
        if(!root->left&&!root->right) {
            
            ++res;
            return true;  //是uni-value
        }
        
        bool a = countUnivalSubtreesHelper(root->left,res);
        bool b = countUnivalSubtreesHelper(root->right,res);
        
        if( a&&b ) {
            if(root->left&&root->left->val!=root->val||root->right&&root->right->val!=root->val) return false;
            
            ++res;
            return true;
            
        }
        
        return false;
    }


    int countUnivalSubtrees(TreeNode* root) {
        
        int res = 0;
        
        countUnivalSubtreesHelper(root, res);
        return res;
    }
};