//Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
//
//Note:
//Given target value is a floating point.
//You are guaranteed to have only one unique value in the BST that is closest to the target.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//很简单，返回谁，谁减谁别搞错了。如果相等或者是叶子，直接返回改点，如果这target小于当前value，可以搜索左子树，否则递归进行右子树

class Solution {
public:

    int closestValue(TreeNode* root, double target) {
        
        if(root->val == target) return root->val;
        
        if(!root->left&&!root->right) return root->val;
        
        if(target < root->val && root->left) {
            int a = closestValue(root->left,target);
            if(root->val-target < abs(a-target)) return root->val;
            
            return a;
        }
        
        if(target > root->val && root->right) {
            int a = closestValue(root->right,target);
            if(target - root->val < abs(a-target)) return root->val;
            
            return a;
        }
        
        

        return root->val;
        
    }
};


//别忘了double 和 int的最大值区别。迭代法其实更快，
    

class Solution {
public:

    int closestValue(TreeNode* root, double target) {
        
        TreeNode* p = root;
        double mini = INFINITY;
        int res;
        
        while(p) {

            if(abs(p->val - target) < mini) {
                mini = abs(p->val - target);
                res = p->val;
            }  
            
            if(target == p->val) return target;
            
            if(target < p->val) {
                p = p->left;
            }
            
            else p = p->right;
            
        }
        
        return res;
        
    }
};
    
    
