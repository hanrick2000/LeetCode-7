//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//


//千万注意此题depth的深度定义是从根到叶子节点的最短路径，并不是最矮层数。并不能简单的将maxdepth的max换成min.
//递归求应该是这样，如果节点为空返回0， 如果节点为叶子返回1，如果节点有左子树，说明节点到左子树会有一条路径，递归调用左子树，如果节点有右子树，说明节点到右子树会有一条路径，递归调用右子树。最后求1+min(左，右)。


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

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        if(!root->left&&!root->right) {
            return 1;
        }
        
        int leftLevel = INT_MAX, rightLevel = INT_MAX;
        
        if(root->left) {  //左子树有叶子节点，进行递归查找路长
            leftLevel = minDepth(root->left);
        }
        
        if(root->right) {  //右子树有叶子节点，进行递归查找路长
            rightLevel = minDepth(root->right);
        }
        
        return 1+min(leftLevel,rightLevel); //取最短。
    }
              
};