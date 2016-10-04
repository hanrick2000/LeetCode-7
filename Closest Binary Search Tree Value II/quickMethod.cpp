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

//按照follow-up的标准来，得实现两个函数，给定一个树节点找到前驱和后继。
//这里类似BST iterator那道题  要通过栈来保存父节点的信息，
//按找后继来，如果root->right,那么在root右子树的最左节点去找，否则我们得找到第一个大于root->val的父亲节点，那个就是后继。所以我们先要找出 >=target的第一个closet节点，然后再BST中搜索它，把它的父亲放入栈中。然后通过那个函数找后继，注意这个getsuccessor和   iterator那道题再 root->right == NULL的情况不同，因为那个iterator是从最小节点一步一步迭代过来的，栈里面始终保存的是没有访问过的节点，即每当root->right为空时，我们直接就可以拿栈顶作为next, 而succussor不同，因为我们不是从最小值开始迭代得到这个栈，我们无法知道按照中序遍历下来的那些父亲节点一定不会在这个栈中，所以得循环找栈顶，找到第一个数值大于root的。
//两个函数实现后，就很好做了

class Solution {
public:
    
    TreeNode* getPredecessor(TreeNode* root, stack<TreeNode*> & pre) {
        if(root->left) {
            root = root->left;

            while(root->right) {
                pre.push(root);
                root = root->right;
            }
            return root;
        }
 
        while(pre.size()&&pre.top()->val > root->val)  pre.pop();

        if(pre.size()) {
            root =  pre.top();
            pre.pop();
            return root;
        }
        return NULL;
    }
    
    TreeNode* getSuccessor(TreeNode* root, stack<TreeNode*> & suc) {
        if(root->right) {
            root = root->right;
            
            while(root->left) {
                suc.push(root);
                root = root->left;
                
            }
            return root;
        }
   
        while(suc.size()&&suc.top()->val < root->val)  suc.pop();

        if(suc.size()) {
            root = suc.top();
            suc.pop();
            return root;
        }
        return NULL;
    }
    

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        
        if(!root) return {};
        
        vector<int> res;
        
        stack<TreeNode*> suc, pre;
        double x1 = abs(root->val - target)+1;
        TreeNode* r = root, *q = NULL, *p = NULL;
        
        while(r)  {
            if(r->val > target) {
                
                if(r->val-target < x1) {
                    x1 = r->val - target;
                    q = r;
                }
                r = r->left;
                
            } else if (r->val == target) {
                q = r;
                break;
            } else {
                r = r->right;
            }
        }
        
        x1 = abs(root->val - target)+1;
        r = root;
        
        while(r)  {
            if(r->val < target) {
                
                if(target-r->val < x1) {
                    x1 = target - r->val;
                    p = r;
                }
                r = r->right;
                
            } else {
                
                r = r->left;
            }
        }
        
        r = root;
        while(r!=q&&q)  {
            if(r->val < q->val) {
                suc.push(r);
                r = r->right;
            }
            else {
                suc.push(r);
                r = r->left;
            }
        }
        r= root;
        while(r!=p&&p) {
            if(r->val > p->val) {
                pre.push(r);
                r = r->left;
            }
            else {
                pre.push(r);
                r = r->right;
            }
        }
        
        while(q && p &&k) {
            double x1 = q->val-target, x2 = target - p->val;
            if(x1 < x2) {
                res.push_back(q->val);
                q = getSuccessor(q,suc);
            }
            
            else {
                res.push_back(p->val);
                p = getPredecessor(p,pre);
            }
            --k;
        }
       
        while(q&&k) {
            --k;
            res.push_back(q->val);
            q = getSuccessor(q,suc);
        }
 
        while(p&&k) {
            --k;
            res.push_back(p->val);
            p = getPredecessor(p,pre);
        }
        
        return res;
    }
};