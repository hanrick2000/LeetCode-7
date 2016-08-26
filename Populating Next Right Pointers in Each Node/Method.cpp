//Given a binary tree
//
//    struct TreeLinkNode {
//      TreeLinkNode *left;
//      TreeLinkNode *right;
//      TreeLinkNode *next;
//    }
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//Note:
//
//You may only use constant extra space.
//You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
//For example,
//Given the following perfect binary tree,
//         1
//       /  \
//      2    3
//     / \  / \
//    4  5  6  7
//After calling your function, the tree should look like:
//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \  / \
//    4->5->6->7 -> NULL


用dfs. 把左右子树各自串起来后，再把左子树的每一个右边节点 同左子树的每一个左边节点连接起来。o（n) 时间 O(1)空间


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connectSub(TreeLinkNode* left,TreeLinkNode* right) {
        TreeLinkNode* p = left, *q = right;
        while(p&&q) {
            p->next = q;
            p = p->right;
            q = q->left;
        }
        
        return;
    }


    void connect(TreeLinkNode *root) {
        if(!root) return;
        
        connect(root->left);
        connect(root->right);
        
        connectSub(root->left,root->right);
    }
};