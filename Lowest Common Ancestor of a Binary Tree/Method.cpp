//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
//
//        _______3______
//       /              \
//    ___5__          ___1__
//   /      \        /      \
//   6      _2       0       8
//         /  \
//         7   4
//For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

这题递归思路是这样的，如果我们能调用递归时返回到底是否在该子树找到一个p,或一个q或两个都找到，如果什么都没找到返回null.
那么调用左子树如果两个都不是空，说明左右两边各找到一个，返回root, 如果只有一个是空，说明另外一个两个都找到了，所以返回那个节点的调用结果.
递归出口，如果root是空返回空，如果root等于其中一个，返回root。


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



    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root) return NULL;
        if(root == p|| root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        
        if(left&&right) return root;
        
        return left?left:right;
        
    }
};