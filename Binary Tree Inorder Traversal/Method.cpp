//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example:
//Given binary tree [1,null,2,3],
//   1
//    \
//     2
//    /
//   3
//return [1,3,2].
//
//Note: Recursive solution is trivial, could you do it iteratively?

，
//步骤是这样的，先从root开始，一边压栈，一边往左下节点走，直到走到最底端，然后从栈里弹出，改点就是当前root的最先遍历点，便利，然后，将root更新到改点的右子树。重新进行上述循环，如果右子树存在，则表明下一次循环时要先访问右子树，右子树不存在的话  就访问上一层父母。




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
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> mystack;
        vector<int> res;
        
        while(root||mystack.size()) {   //每一次进循环都是中序访问以root为根节点的子树。  如果root为空 从栈里弹出之前的节点，注意这种节点的左子树肯定访问过，所以就访问本身，再访问右子树。
            
            while(root){   //root存在
                mystack.push(root);
                root = root->left;
            }
            
            root = mystack.top();
            mystack.pop();
            res.push_back(root->val);
            
            root = root->right;
        }
    
        return res;
        
    }
};