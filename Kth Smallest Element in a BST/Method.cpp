//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
//Follow up:
//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
//
//Hint:
//
//Try to utilize the property of a BST.
//What if you could modify the BST node's structure?
//The optimal runtime complexity is O(height of BST).

按照中序遍历BST，当访问到第k节点就可以了。注意k是相当于全局变量，要引用。
follow up: 需要在节点中额外保存当前节点是第i大的元素，这样就可以通过对这个域进行二分查找找到。耗时O(lgn)同时在插入删除时也要维护这个值。

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

    void kthSmallestHelper(TreeNode* root, int &k, int &e) {
        if(!root) return;
        
        kthSmallestHelper(root->left, k,e);
        --k;
        
        if(!k) {
            e = root->val;
            return;
        }
        
        kthSmallestHelper(root->right, k,e);   
    }

    int kthSmallest(TreeNode* root, int k) {

        
        int e;
        kthSmallestHelper(root, k,e);
        return e;
        
    }
};
