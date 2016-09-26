//The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
//
//Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
//Example 1:
//     3
//    / \
//   2   3
//    \   \ 
//     3   1
//Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//Example 2:
//     3
//    / \
//   4   5
//  / \   \ 
// 1   3   1
//Maximum amount of money the thief can rob = 4 + 5 = 9.

//动态规划和dfs的结合，每一次dfs返回都要返回改点偷得最大值和不偷的最大值。进行动态规划。注意不偷的最大值比较容易出bug,就是是左子树偷/不偷的最大值 与 右子树偷/不偷的最大值的4种组合取最大。

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
    int rob(TreeNode* root, int &no) {
        if(!root) {
            no = 0;
            return 0;
        }
        
        int noleft = 0, noright = 0, left = 0, right = 0;
            
        left = rob(root->left, noleft);
        
        right = rob(root->right, noright);
        
        no = max(max(max(left + right, noleft + noright),left + noright),noleft + right) ;
        
        return noleft + noright + root->val;
    }

    int rob(TreeNode* root) {
        
        int no = 0, yes = rob(root,no);
        
        return max(no, yes);
    }
};