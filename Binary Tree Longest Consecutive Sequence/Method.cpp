//Given a binary tree, find the length of the longest consecutive sequence path.
//
//The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
//
//For example,
//   1
//    \
//     3
//    / \
//   2   4
//        \
//         5
//Longest consecutive sequence path is 3-4-5, so return 3.
//   2
//    \
//     3
//    / 
//   2    
//  / 
// 1
//Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

//思想很简单的，dfs,然后每一次递归要把以改点开头的最大长度返回过来，这样，调用的函数才可以知道以自己开头的最大长度是多少。然后有一个全局变量被改。

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

    int longestConsecutiveHelper(TreeNode* root, int &num) {
        
        if(!root) return 0;

        int res = 1;
        if(root->left) {
            int left = longestConsecutiveHelper(root->left,num);
            if(root->val + 1 == root->left->val) res = max(res, left+1);
        }
        
        if(root->right) {
            int right = longestConsecutiveHelper(root->right, num);
            if(root->val + 1 == root->right->val) res = max(res, right+1);
        }        
        
        num = max(res,num);
        
        return res;
        
    }

    int longestConsecutive(TreeNode* root) {
        
        int num = 0;
        longestConsecutiveHelper(root, num);
        return num;
    }
};