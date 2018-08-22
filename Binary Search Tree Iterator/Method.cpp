//Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.
//
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
//
//Credits:
//Special thanks to @ts for adding this problem and creating all test cases.

//这题其中一个思路是，反复调用next()肯定是中序遍历bst的每一步骤。所以平均下来调用n个next遍历一棵树后，相当于每一个node都入栈出战一次，o（2n) = O(n). 而判断有没有遍历完，就可以看有没有右子树，或者栈里面有没有元素。 初始化时，得新建一个节点，将代访问树变成右子树。

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    
    stack<TreeNode*> mystack;
    TreeNode* iter;
    
public:
    BSTIterator(TreeNode *root) {
        TreeNode* newRoot = new TreeNode(0);
        newRoot->right = root;
        iter = newRoot;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        
        return iter->right||mystack.size();
        
    }

    /** @return the next    smallest number */
    int next() {
        
        if(iter->right) {
            iter = iter->right;
            while(iter->left) {
                mystack.push(iter);
                iter = iter->left;
            }
            return iter->val;
        }

        iter = mystack.top();
        mystack.pop();
        return iter->val;

    }
};

这个版本就是inorder，改变过来的非常简单。while的条件就是hes next. while里面的内容就是next.

class BSTIterator {
    TreeNode *myroot;
    stack<TreeNode*> mystack;
public:
    BSTIterator(TreeNode *root) {
        myroot = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return myroot || mystack.size();
    }

    /** @return the next smallest number */
    int next() {
        while(myroot) {
            mystack.push(myroot);
            myroot = myroot->left;
        }
        myroot = mystack.top();
        int res = myroot->val;
        mystack.pop();
        myroot = myroot->right;
        return res;
        
    }
};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */