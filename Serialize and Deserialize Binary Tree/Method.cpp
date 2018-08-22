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
    
    这是类似于leetcode OJ那种方法，按照层序遍历来的（BFS队列）,不过我这种没有把尾部的N全部去掉 [1,2,3,N,N,N,N].（其实leetcode去没去掉也不好说）反正serialize按照层序遍历，记住NULL也得加到队列里，因为下一层的NULL，如果后面有非空节点，这个NULL也得输出在string上。所以最后一些NULL，没办法避免。
        
    deserilize时 ， 也用一个队列，记录当前是哪一个节点要构造左孩子还是右孩子。每次从队列中pop.如果是当前字符是N，直接continue，如果不是，得构造一个节点t，当前节点的左孩子==t, 当前节点的右孩子==下一个t.然后这个节点构造完毕了。自动挪到下一个节点。
    
    string serialize(TreeNode* root) {

        queue<TreeNode*> myque;
        myque.push(root);
        
        string res;
        
        while(myque.size()) {
            
            TreeNode* tmp = myque.front();
            myque.pop();
            
            if(!tmp) {
                res += "N,";
                continue;
            }
            
            res += to_string(tmp->val) + ',';
            
            myque.push(tmp->left);
    
            myque.push(tmp->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        string t;
        bool left = false;
        
        TreeNode* root = new TreeNode(0), *cur = root;
        
        queue<TreeNode*> myque;
        
        for(int i = 0; i < data.size(); ++i) {
            if(data[i] == ',') {
            
                TreeNode *tmp = NULL;
                
                if(t != "N") {
                    tmp = new TreeNode(stoi(t));
                    myque.push(tmp);
                }
                if(left) {
                    cur -> left = tmp;
                    left = false;
                } else {
                    cur -> right = tmp;
                    left = true;
                    if(myque.empty()) {
                        break;
                    }
                    cur = myque.front();
                    myque.pop();
                }
                t = "";
                
            } else {
                t += data[i];
            }
        }
        
        cur = root->right;
        delete root;
        
        return cur;
    }
    
    这个版本是用preorder（dfs）的.  注意serelize 和BFS很像.只是把队列换成了栈。而deserilize 完全不同，我们本质也想对每一个点记录这个点的左孩子构造了完没有，下一次是构造左孩子还是右孩子但和bfs不同，bfs每一次构造完当期那节点的左孩子时，下一次直接就构建它的右孩子了，所以只需一个全局变量不断的flip就可以了。  而dfs每一个节点的左孩子构建完后我们又要构建它左孩子的左孩子去了，所以下次再回来构建它时我们到底是添加在左孩子还是右孩子？ 所以我们得拿一个栈保存节点已经一个对应的bool 值，如果这个值true，可以把当前节点插在栈顶节点的左孩子，否则建在右孩子，如果栈顶右孩子建完后，肯定没有它什么事了，贪走就好，剩下的都在处理 它的右子树。
    
    string serialize(TreeNode* root) {
        
        stack<TreeNode*> mystack;
        mystack.push(root);
        
        string res;
        
        while(mystack.size()) {
            
            TreeNode* tmp = mystack.top();
            mystack.pop();
            
            if(!tmp) {
                res += "N,";
                continue;
            }
            res += to_string(tmp->val) + ',';
            mystack.push(tmp->right);
            mystack.push(tmp->left);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = new TreeNode(0);
        
        stack<pair<TreeNode*,bool>> mystack;
        
        string t;
        mystack.push({root,false});
        
        for(int i = 0; i < data.size(); ++i) {
            
            if(data[i] == ',') {
                
                TreeNode * p = t=="N"? NULL: new TreeNode(stoi(t));  //构造当前节点。。
                
                if(mystack.top().second) {  //如果要构造右孩子
                    
                    mystack.top().first->right = p;  //栈顶接上
                    mystack.pop();  //滚

                } else {  //接左孩子
                    mystack.top().first->left = p;  
                    mystack.top().second = true;  //设置变量下次构建右孩子
                }

                if(p) mystack.push({p,false});  //如果当前节点非空，push.
                
                t = "";
                
            }  else {
                t += data[i];
            }
        }

        return mystack.top().first->left;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));