//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

//和inorder－preorder套路一样的。注意要给

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

    TreeNode* buildTreeHelper(vector<int>& inorder, int i_s, int i_e, vector<int>& postorder, int p_s, int p_e, unordered_map<int,int> &mymap) {
        if(p_e - p_s<1) return NULL;
        
        
        TreeNode* root = new TreeNode(postorder[p_e-1]);
        
        int pos = mymap[postorder[p_e-1]];
        
        root->left = buildTreeHelper(inorder,i_s,pos,postorder,p_s,p_s+pos-i_s,mymap);
        root->right = buildTreeHelper(inorder, pos+1,i_e , postorder, p_s+pos-i_s, p_e-1,mymap);
        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mymap;
        
        for(int i = 0; i < inorder.size(); ++i) {
            mymap[inorder[i]] = i;
        }
        
        return buildTreeHelper(inorder,0,inorder.size(), postorder, 0, postorder.size(),mymap);
    }
};