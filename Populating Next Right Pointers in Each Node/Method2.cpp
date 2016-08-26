还有一种方法：连接当前子树只要三步：
1）将左孩子与右孩子连起来
2）将右孩子与兄弟的左孩子连起来
3）递归处理左子树和右子树


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    void connect(TreeLinkNode *root) {
        if(!root) return;
        
        if(root->left) {
            root->left->next = root->right;    
        }
        
        if(root->next&&root->right) {
            root->right->next = root->next->left;
        }
            
        connect(root->left);
        connect(root->right);

    }
};