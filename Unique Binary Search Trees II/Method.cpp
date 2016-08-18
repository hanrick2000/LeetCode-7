//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//For example,
//Given n = 3, your program should return all 5 unique BST's shown below.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//动态规划，递归方法和上一题一样，我们要做的是，一步一步构造出1,2,3...n-1的从1到k的bst，然后求n时，选定1到n作为根节点，左子树是所有的k个bst，右子树是所有的n-k-1个bst，还要为每一个节点增加k个位移量。

class Solution {
public:

    TreeNode* offset(const TreeNode* root,int k) {  //给一刻bst增加位移量，注意不能修改原树，因为要重复利用
        if(!root) return NULL;
        
        TreeNode *newRoot = new TreeNode(root->val+k);
        newRoot->left = offset(root->left,k);
        newRoot->right = offset(root->right,k);
        return newRoot;
        
    }

    vector<TreeNode*> generateTreesHelper(int n, vector<vector<TreeNode*>> &res) {
        if(n==0) return {NULL};
        if(n==1) return {new TreeNode(1)};
        
        if(res[n-1].size()) {  //已经求过结构，直接返回
            return res[n-1];
        }
        vector<TreeNode*> r;
        for(int i = 0; i < n; ++i) {//迭代每一个根节点
            for(int j = 0; j < generateTreesHelper(i,res).size(); ++j) {  //迭代每一左子树
                TreeNode* left = generateTreesHelper(i,res)[j];
                for(int k = 0; k < generateTreesHelper(n-1-i,res).size(); ++k) {//迭代每一右子树
                    TreeNode* root = new TreeNode(i+1);
                    root->left = left;
                    TreeNode* right = generateTreesHelper(n-1-i,res)[k];
                    root->right = offset(right,i+1);  //设定完便宜量
                    r.push_back(root);    //增添
                    
                }
            }
        }
        
        res[n-1] = r;
        return r;
        
    }

    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        vector<vector<TreeNode*>> res(n);   //动态规划的数组
         
        
        return generateTreesHelper(n,res);
    }
};
    
    