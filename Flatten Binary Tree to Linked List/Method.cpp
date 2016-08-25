//Given a binary tree, flatten it to a linked list in-place.
//
//For example,
//Given
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
//The flattened tree should look like:
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6


//dfs递归，先将右子树flatten，如果有左子树，将左子树flatten，flatten后的那个右下角的点练到右子树，左子树复制给右子树，左子树清空


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

    TreeNode* flattenHelper(TreeNode* root) {
        if(!root) return root;
        flattenHelper(root->right);
        if(root->left) {
            flattenHelper(root->left)->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }


        
        TreeNode* p = root;
        
        while(p->right) {
            p = p->right;
        }
        
        return p;  //返回右下角的点。
    }
    

    void flatten(TreeNode* root) {
        
        flattenHelper(root);
    }
};