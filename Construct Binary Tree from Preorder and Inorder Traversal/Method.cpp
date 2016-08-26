//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

//根据preorder第一个数确定是根
//然后找到inorder的这个数，前边就是左子树的inorder，后边就是右子树inorder。
//然后在preorder的第一个数之后找到左子树这么长，这就是左子树的preorder，剩下的是右子树的preorder。
//递归。

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

    TreeNode* buildTreeHelper(vector<int>& preorder, int p_s, int p_e, int i_s, int i_e, vector<int>& inorder, unordered_map<int,int> &mymap) {
        if(p_e - p_s<1) return NULL;
        
        
        TreeNode* root = new TreeNode(preorder[p_s]);
        
        int pos = mymap[preorder[p_s]];
        
        root->left = buildTreeHelper(preorder,p_s+1,p_s+pos-i_s+1,i_s,pos,inorder,mymap);
        root->right = buildTreeHelper(preorder, p_s+pos-i_s+1 ,p_e , pos+1, i_e,inorder,mymap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mymap;
        
        for(int i = 0; i < inorder.size(); ++i) {
            mymap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder,0,preorder.size(),0,inorder.size(),inorder,mymap);
        
    }
};