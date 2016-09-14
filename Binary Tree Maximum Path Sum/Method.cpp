//Given a binary tree, find the maximum path sum.
//
//For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.
//
//For example:
//Given the below binary tree,
//
//       1
//      / \
//     2   3
//Return 6.

//这题思路也很明显，递归遍历左右子树，每一次递归遍历，都要计算出一条从左子树经过根经过右子树的最大值，更新maxi,而也要向parent节点返回一条经过root但是不能有分叉的path的最大值，及三种可能，root, root->root->left, root->root->right. 可以通过修改根节点的val来向parent提供。


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

    void dfs(TreeNode* root, int &maxi) {
        if(!root) return;
        
        int tmp = 0;
        if(root->left) {
            dfs(root->left,maxi);
            if(root->left->val>0)
                tmp+=root->left->val;
        }
        
        if(root->right) {
            dfs(root->right,maxi);
            if(root->right->val>0) 
                tmp+=root->right->val;
        }
        
        tmp += root->val;
        maxi = max(maxi,tmp);
        
        int left = max(root->left?root->left->val:0,0);
        int right = max(root->right?root->right->val:0,0);
        
        root->val += max(left,right);
        
    }


    int maxPathSum(TreeNode* root) {
        
        int maxi = INT_MIN;
        dfs(root,maxi);
        return maxi;
        
    }
};