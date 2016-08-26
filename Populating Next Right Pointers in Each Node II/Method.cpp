//Follow up for problem "Populating Next Right Pointers in Each Node".
//
//What if the given tree could be any binary tree? Would your previous solution still work?
//
//Note:
//
//You may only use constant extra space.
//For example,
//Given the following binary tree,
//         1
//       /  \
//      2    3
//     / \    \
//    4   5    7
//After calling your function, the tree should look like:
//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \    \
//    4-> 5 -> 7 -> NULL



//一种做法是还是自底向上把子树连好以后，从root起将两棵子树之间的所有分叉给连接起来，此时需要找到左子树的每一层的最右边节点和右子树的每一层的最左边节点，把这些节点全部连接起来。t(n) = 2t(n/2) + O(log n *log n). t(n) = O(n)
    
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
    
    
    int level(TreeLinkNode* root) {
        return root?1+max(level(root->left),level(root->right)):0;
    }

    void findright(TreeLinkNode* root, int depth, TreeLinkNode* &rst) {
        if(!root) {
            return;
        }
        
        if(!depth) {
            rst = root;
            return;
        }
        
        
        findright(root->left,depth-1,rst);
        findright(root->right,depth-1,rst);
        
        
    }

    void findleft(TreeLinkNode* root, int depth, TreeLinkNode* &rst) {
        if(!root) {
        
            return;
        }
        
        if(!depth) {
            rst = root;
            return;
        }
        
        
        findleft(root->right,depth-1,rst);
        findleft(root->left,depth-1,rst);
        
    }


    void connectSub(TreeLinkNode* left,TreeLinkNode* right) {
        TreeLinkNode* p=NULL, *q=NULL;
        
        int len = min(level(left),level(right));
        for(int i = 0; i < len; ++i) {
            findright(left,i,p);
            findleft(right,i,q);

            p->next = q;
            
        }

    }

    void connect(TreeLinkNode *root) {
        if(!root) return;
        
        connect(root->left);
        connect(root->right);
        
        connectSub(root->left,root->right);
    }
};