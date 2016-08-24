方法一中每一次递归判断还要子底向上判断两个左子树，然后还要再自底向上计算左子树的最大值和右子树的最小值。我们可以通过一次递归就返回当前节点是否是bst，以及顺带用当前节点的val记录当前子树的最大值，用返回值mini,记录当前子树的最小值。

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

    
    bool isValidHelper(TreeNode* root, int &mini) {
        if(!root) return true;
        
        if(!isValidHelper(root->left,mini)) return false;
        int tmp = mini; //左子树的最小值会是该子树返回的最小值
        if(!isValidHelper(root->right,mini)) return false;

        bool t =  (!root->left||root->left->val<root->val) && (!root->right||mini>root->val);
        
        root->val = root->right?root->right->val:root->val;
        mini = root->left?tmp:root->val;
        return t;     
    }


    bool isValidBST(TreeNode* root) {
        
        int mini = 0;
        return isValidHelper(root,mini);
        
    }
};