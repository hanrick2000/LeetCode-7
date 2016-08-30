//Given a binary tree, return the postorder traversal of its nodes' values.
//
//For example:
//Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
//return [3,2,1].
//
//Note: Recursive solution is trivial, could you do it iteratively?

思想很简单，每一次循环看栈顶这个点，如果栈顶这个点 对至少有一个孩子的节点，必须先访问它们，肯定是将其右孩子压入栈，左孩子压入栈，得一会先访问左右孩子。第二次访问就直接弹出栈。如果这个点没有孩子或者孩子访问完毕，就访问该点。 问题是怎么知道孩子访问过了？我们可以控制一个pre指针，每一次访问过一个节点，就保存给pre，每一次检测该节点的左孩子和右孩子是否访问过，就看pre是否等于左孩子或右孩子，且pre要不等于空。



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
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root) return {};
        
        TreeNode* pre = NULL;
        stack<TreeNode*> mystack;
        mystack.push(root);
        vector<int> res;
        
        
        while(mystack.size()) {
            TreeNode* root1 = mystack.top();
            
            if((!root1->left&&!root1->right)||(pre&&(pre == root1->left||pre == root1->right))) {
                
                res.push_back(root1->val);
                pre = root1;
                mystack.pop();
                
            }
            
            else {
                if(root1->right) {
                    mystack.push(root1->right);
                }
                
                if(root1->left) {
                    mystack.push(root1->left);
                }
            }
        }
        
        
        return res;
        
    }
};
