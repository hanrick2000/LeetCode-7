//Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.
//
//Note:
//A subtree must include all of its descendants.
//Here's an example:
//    10
//    / \
//   5  15
//  / \   \ 
// 1   8   7
//The Largest BST Subtree in this case is the highlighted one. 
//The return value is the subtree's size, which is 3.
//Hint:
//
//You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
//Follow up:
//Can you figure out ways to solve it with O(n) time complexity?

//这题跟valid BST树一样，不过需要在dfs返回时额外提供改点是否是BST以及改点下最大的BST数值是多少

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

    int findleftMax(TreeNode* root) {
        while(root->right) root = root->right;
        
        return root->val;
    }
    
    
    int findrightMin(TreeNode* root) {
        while(root->left) root = root->left;
        
        return root->val;
    }

    int largestBSTSubtree(TreeNode* root, bool &e) {
    
        if(!root) {
            e = true;
            return 0;
        }
        bool a, b;
        
        int left = largestBSTSubtree(root->left,a);
        int right = largestBSTSubtree(root->right,b);
        
        if(a&&b){

            int l = 0, r = 0;
            
            if(root->left) {
                l = findleftMax(root->left);
                if(l >=  root->val) {
                    e = false;
                    return max(left,right);
                }
            }
            
            if(root->right) {
                r = findrightMin(root->right);
                if(r <=  root->val) {
                    e = false;
                    return max(left,right);
                }
            }
            
            e = true;

            return left+right+1;
        }

        
        e = false;
        return max(left,right);
        
    }

    int largestBSTSubtree(TreeNode* root) {
        
        bool e = true;
        
        return largestBSTSubtree(root,e);
        
    }
    
    
        bool isBST(TreeNode* root, int &l, int &r, int &res) {
        
        if(!root) return true;
        
        int l1, r1, l2, r2;
        bool flag = true;
        
        if(root->left) flag = isBST(root->left, l1, r1, res);
        
        if(root->right) flag &= isBST(root->right, l2, r2, res);
        
        l = root->left? l1 : root->val;
        r = root->right? r2 : root->val;
        
        if(!flag) {
            root->val = 0;
            return false;
        }
        
        if(root->left && r1 > root->val || root->right && l2 < root->val) {
            root->val = 0;
            return false;
        }
        
        root->val = 1;
        if(root->left) root->val += root->left->val;
        if(root->right) root->val += root->right->val;
        
        res = max(res, root->val);
        
        return true;
    }


    int largestBSTSubtree(TreeNode* root) {
        int l, r, res = 0;
        isBST(root, l,r, res);
        return res;
    }
};