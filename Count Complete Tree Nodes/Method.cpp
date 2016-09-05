//Given a complete binary tree, count the number of nodes.
//
//Definition of a complete binary tree from Wikipedia:
//In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
//
//Show Tags
//Show Similar Problems



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//这题两个通常的做法：
//1) 每当到一个点，判断沿左子树一直走下去 和  沿右子树一直走下去是否相等，如果相等，说明是满二叉树，直接返回2*高度-1, 否则递归调用左子树+右子树+1.
//复杂度：由于每一个完全二叉树至少有一个子树是满二叉树，所以T(n) = T(n/2) + o(lg n)
//T(n) = O (lg n *lg n)
//    
//2) 更巧妙的做法
//    
//    1           1
//  2   3   与   2   3    
// 4            4 5 6
//   
//在于1的左子树下沿着左孩子的长度和右子树下沿着左边孩子长度是否相等，如果相等，则左子树是满二叉树，否则右子树是满二叉树。加上满二叉树的节点数后，对另一个子树递归调用，始终记得，左边的长度不用每一次重新算，只要第一次算完之后每一次-1就可以,右边得算。
//复杂度一样。
    
解法一：
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
    int countNodes(TreeNode* root) {
        
        if(!root) return 0;
        
        TreeNode* p = root, *q = root;
        int r = 0;
        
        while(q) {
            ++r;
            p = p->left;
            q = q->right;
        }
        
        if(!p) {
            return (1<<r)-1;
        }
        
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};


解法二迭代：
class Solution {
public:
    int countNodes(TreeNode* root) {
        
        if(!root) return 0;
        
        int sum = 0, left = 0;
        for(TreeNode* p =root->left; p; p = p->left) ++left;
        
        while(root) {
            int right = 0;

            for(TreeNode* p =root->right; p; p = p->left) ++right;
            
            if(left == right) {
                sum += 1<<left;
                root = root->right;
            }
            else {
                sum += 1<<right;
                root = root->left;
            }
            --left;
            
        }
        
        return sum;
        
    }
};

解法二递归：

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

    int countNodesHelper(TreeNode* root, int left)  {
        if(!root) return 0;
        
        TreeNode* p = root;
        int right = 0;

        for(TreeNode* p = root->right; p; p = p->left, ++right);

        if(left == right) {
            return (1 << left) + countNodesHelper(root->right, --left);
        }
        
        return (1<<right) + countNodesHelper(root->left, --left);
    }

    int countNodes(TreeNode* root) {
        
        if(!root) return 0;
        
        int left = 0;

        for(TreeNode* p = root->left; p; p = p->left, ++left);
        
        return countNodesHelper(root, left);
        
        
    }
};