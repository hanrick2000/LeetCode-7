//Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
//
//Note:
//Given target value is a floating point.
//You may assume k is always valid, that is: k ≤ total nodes.
//You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
//Follow up:
//Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
//
//Hint:
//
//Consider implement these two helper functions:
//getPredecessor(N), which returns the next smaller node to N.
//getSuccessor(N), which returns the next larger node to N.
//Try to assume that each node has a parent pointer, it makes the problem much easier.
//Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
//You would need two stacks to track the path in finding predecessor and successor node separately.


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

    void preOrder(TreeNode* root, vector<int> &data) {
        if(!root) return;
        preOrder(root->left,data);
        
        data.push_back(root->val);
        
        preOrder(root->right, data);
        return;
    }

    int binarySearch(vector<int> &data, double target) {
        
        int p = 0, q = data.size()-1;
        
        while(p < q) {
            
            int c = (q-p)/2 + p;
            
            if(data[c] >= target) q = c;
            
            else {
                p = c + 1;
            }
        }

        return data[p] >= target? p: p+1;
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        
        vector<int> data;        
        preOrder(root, data);
        
        vector<int> res;
        
        int q = binarySearch(data,target), p = q-1;
        
        while(q < data.size() && p >= 0 &&k) {
            double x1 = data[q]-target, x2 = target - data[p];
            if(x1 < x2) {
                res.push_back(data[q++]);
            }
            
            else {
                res.push_back(data[p--]);
            }
            --k;
        }
       
        while(q < data.size()&&k) {
            --k;
            res.push_back(data[q++]);
        }
 
        while(p>=0&&k) {
            --k;
            res.push_back(data[p--]);
        }
        
        return res;
    }
};