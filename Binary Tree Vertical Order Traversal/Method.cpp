//Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
//
//If two nodes are in the same row and column, the order should be from left to right.
//
//Examples:
//
//Given binary tree [3,9,20,null,null,15,7],
//   3
//  /\
// /  \
// 9  20
//    /\
//   /  \
//  15   7
//return its vertical order traversal as:
//[
//  [9],
//  [3,15],
//  [20],
//  [7]
//]
//Given binary tree [3,9,8,4,0,1,7],
//     3
//    /\
//   /  \
//   9   8
//  /\  /\
// /  \/  \
// 4  01   7
//return its vertical order traversal as:
//[
//  [4],
//  [9],
//  [3,0,1],
//  [8],
//  [7]
//]
//Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
//     3
//    /\
//   /  \
//   9   8
//  /\  /\
// /  \/  \
// 4  01   7
//    /\
//   /  \
//   5   2
//return its vertical order traversal as:
//[
//  [4],
//  [9,5],
//  [3,0,1],
//  [8,2],
//  [7]
//]

这题一定要BFS， 因为上层的一定要先于下层出现，用一个Node把tree包起来，加一纵坐标变量。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct Node {
    TreeNode* treeNode;
    int pos;
    Node(TreeNode* t, int p): treeNode(t), pos(p) {}
};
 
class Solution {
public:

    void verticalOrderHelper(TreeNode* root, map<int, vector<TreeNode*>> &mymap, int k) {
        
        if(!root) return;
        
        mymap[k].push_back(root);
        
        verticalOrderHelper(root->left, mymap, k-1);
        
        verticalOrderHelper(root->right, mymap, k+1);
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        if(!root) return {};
        
        map<int, vector<TreeNode*>> mymap;
        
        queue<Node> myque;
        myque.push(Node(root,0));
        
        while(myque.size()) {
            
            int len = myque.size();
            
            for(int i = 0; i < len; ++i) {
                Node tmp = myque.front();
                myque.pop();
                mymap[tmp.pos].push_back(tmp.treeNode);
                if(tmp.treeNode->left) {
                    myque.push(Node(tmp.treeNode->left,tmp.pos-1));
                }
                
                if(tmp.treeNode->right) {
                    myque.push(Node(tmp.treeNode->right,tmp.pos+1));
                }
            }
        }
        
        vector<vector<int>> res;
        
        for(auto it = mymap.begin(); it != mymap.end(); ++it) {
            
            vector<int> tmp;
            for(auto x: it->second) {
                tmp.push_back(x->val);
            }
            
            res.push_back(tmp);
            
        }
        return res;
        
    }
};