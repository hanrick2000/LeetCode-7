//Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
//Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
//For example, you may serialize the following tree
//
//    1
//   / \
//  2   3
//     / \
//    4   5
//as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
//Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

//可以递归的serielize左子树和右子树，用括号括起来，然后左子树和根加一个运算符，根和右子树加另一个运算符。deserialize时可以按照表达式求解的方法去做。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root) return "N";

        return "((" + serialize(root->left) + ")+" + to_string(root->val) + "*(" + serialize(root->right) +"))";      
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        stack<char> tokens;
        stack<TreeNode*> nodes;
        
        for(int i = 0; i < data.size(); ++i) {
            char c = data[i];
            if(c == '(') tokens.push(c);
            else if(c == ')') {
                
                while(tokens.top()!= '(') {
                    TreeNode* p = nodes.top();
                    nodes.pop();
                    TreeNode* q = nodes.top();
                    nodes.pop();                
                    
                    char t = tokens.top();
                    
                    if(t == '+') {
                        p->left = q;
                        nodes.push(p);
                    }
                    else {
                        q->right = p;   
                        nodes.push(q);
                    }
                    tokens.pop();
                }
                tokens.pop(); //pop '('
                
            }
            
            else if(c == '+') {
                
                tokens.push(c);
            }
            
            else if(c == '*') {
                char t = tokens.top();
                tokens.pop();
                TreeNode* p = nodes.top();
                nodes.pop();
                TreeNode* q = nodes.top();
                nodes.pop();

                p->left = q;
                nodes.push(p);
                
                tokens.push(c);
            }
            
            else if (c == 'N') {
                nodes.push(NULL);
            }
        
            else {
                bool sign = false;
                if(c == '-') {
                    ++i;
                    sign = true;
                }
                
                long long tmp = 0;
                while(i < data.size() && data[i] >='0' && data[i] <='9') {
                    tmp = tmp*10 + data[i] - '0';
                    ++i;
                }
                --i;
                if(sign) tmp = -tmp;
                TreeNode* p = new TreeNode(tmp);
                
                nodes.push(p);
            }
        }
      
        return nodes.top();

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));