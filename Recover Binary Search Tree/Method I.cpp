//Two elements of a binary search tree (BST) are swapped by mistake.
//
//Recover the tree without changing its structure.
//
//Note:
//A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?


//很naive的算法，先中序遍历，得到值得序列，肯定有两个点是无序的，
//    
//这里有两种情况：1) 1234 -> 3214     2)1234 -> 2134
//第一种情况有2次 前面数大于紧邻数，3>2，2>1,我们要换的是3和1  第二种情况仅有一次2>1.
//所以得到序列后，我们要找到1次或2次前面数大于紧邻数的情况，然后进行交换。


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
    
    void inOrder(TreeNode* root, vector<int> &seq) {
        if(!root) return;
        
        inOrder(root->left,seq);
        
        seq.push_back(root->val);
        
        inOrder(root->right,seq);
        
    }
    
    void change(TreeNode* root, int a, int b) {
        
        stack<TreeNode*> mystack;
        mystack.push(root);
        
        while(mystack.size()) {
            TreeNode* tmp = mystack.top();
            mystack.pop();
            
            if(tmp->val == a) {
                tmp->val = b;
            }
            
            else if(tmp->val == b) {
                tmp->val = a;
            }
            
            if(tmp->right) {
                mystack.push(tmp->right);
            }           
            
            
            if(tmp->left) {
                mystack.push(tmp->left);
            }
    
        }
        
        return;
    }
    

    void recoverTree(TreeNode* root) {
        vector<int> seq;
        
        
        inOrder(root,seq);
        
        
        int first = -1, second = -1;
        
        for(int i = 0; i < seq.size()-1; ++i) {
            if(seq[i]>seq[i+1]) {
                if(first==-1) {
                    first = i;
                }

                else {
                    second = i;
                }
            }
            
        }
        
        // cout<<first<<endl;
        // cout<<second<<endl;
        
        
        if(second==-1)  {
            change(root,seq[first],seq[first+1]);
        }
        
        else {
            change(root,seq[first],seq[second+1]);
        }
            
    }
};