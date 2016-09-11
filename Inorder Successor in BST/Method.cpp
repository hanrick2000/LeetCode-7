//Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
//
//Note: If the given node has no in-order successor in the tree, return null.

//一开始往迭代的思路去做，如果p有右孩子，得返回，有孩子的最左下角节点。否则，我们从root开始找p，如果期间有值比p大的就不断更新结果rst,直到搜到p.那个rst就是结果，初始记得设为NULL.

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *rst = NULL;
        
        if(p->right) {
            p = p->right;
            while(p->left) p = p->left;

            return p;
        }
        
        while(root&&root!=p) {
            if(root->val > p->val) {
                rst = root;
                root = root->left;
            }
            
            else {
                root = root->right;
            }
        }
        
        return rst;
        
    }
};

//递归：如果root为空返回空，如果root的值小于p的值，返回root右子树的查找结果。
//    否则在左子树里查找，如果返回非空就是结果，否则就是root.


class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return NULL;
        
        if(root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        }
            
        TreeNode* t = inorderSuccessor(root->left,p);
        
        if(t) return t;
        return root;
      
    }
};