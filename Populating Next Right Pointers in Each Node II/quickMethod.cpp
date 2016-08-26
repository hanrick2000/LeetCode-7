根据I的第二种解法，只要把当前树的左右子树连起来，这个右边的节点和同层的最靠近的节点连起来。

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
        
        
        if(root->left) {    // 有左孩子，将左右孩子试签一下
            root->left->next = root->right;
        }
        
        TreeLinkNode* p = root->next;  // 还得和父亲兄弟的孩子试签一下
        TreeLinkNode* node = root->right? root->right:root->left;   //右孩子存在，就让右孩子牵，否则还得左孩子签，用node表示
            
        if(!node) return; //左孩子也不在 说明不用连线了，后面的递归也不用进行
        
        //和父亲兄弟的孩子牵手
        
        while(p) {
            if(p->left) {
                node->next = p->left;
                break;
            }
            if(p->right) {
                node->next = p->right;
                break;
            }
            p = p->next;
                    
        }

        connect(root->right);   //这一步很重要，我们一定要先保证上一层右侧的牵手全部完成。所以可以从右边开始dfs.
        
        connect(root->left);
        
    }
};