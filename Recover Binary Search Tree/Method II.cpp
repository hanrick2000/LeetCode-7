/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
方法二，尽量不要额外申请空间，不用那个高级的morris 遍历数法，只好勉强的用递归了，毕竟它是系统开辟的栈空间。
就是一遍深度遍历时记录下上一个节点，并比较，最后交换这两个逆序的节点的值。

class Solution {

TreeNode* lastNode;
TreeNode* big;
TreeNode* small;

public:
    
    void inOrder(TreeNode* root) {
        if(!root) return;
        
        inOrder(root->left);
        
        if(lastNode && root->val<lastNode->val) {
            
            small = root;
            if(!big) {
                big = lastNode;
                
            }
            else {
                return;
            }
        }
        
        lastNode = root;
        inOrder(root->right);
        
    }
    
    void recoverTree(TreeNode* root) {

        inOrder(root);

        swap(big->val,small->val);
    }
};