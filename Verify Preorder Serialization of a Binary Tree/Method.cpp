//One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
//
//     _9_
//    /   \
//   3     2
//  / \   / \
// 4   1  #  6
/// \ / \   / \
//# # # #   # #
//For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
//
//Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
//
//Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
//
//You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
//
//Example 1:
//"9,3,4,#,#,1,#,#,2,#,6,#,#"
//Return true
//
//Example 2:
//"1,#"
//Return false
//
//Example 3:
//"9,#,#,1"
//Return false

这题还得好好想想。  我们可以用栈来模拟先序遍历的流程。不过思路稍有不同，先在一个栈里面压入true。我们假设每新遇到一个节点，就向栈里面压进一个false，表示这个节点的左孩子是否被访问过，然后从头开始。  第一个节点，会被push一个false，当新的节点进栈时，将栈顶节点的false置true。表示该新节点是父节点的左孩子，如果栈顶之前是true，表明父节点的右孩子找到了，弹出父节点。如果该节点不是"#", 也进栈。过程中如果有栈空的情况，或者扫描结束后栈还是没空，就是false。


class Solution {
public:
    bool isValidSerialization(string &preorder) {

        stack<int> mystack;
        mystack.push(1);
        preorder += ',';
        
        string token;
        for(int i = 0; i < preorder.size(); ++i) {
            
            if(preorder[i] == ',') {
                if(mystack.empty()) return false;

                if(mystack.top()) mystack.pop();
                    
                else ++mystack.top();
                    
                if(token != "#") mystack.push(0);

                token = "";
                    
            }
            
            else {
                token += preorder[i];
            }
        }
        
        return mystack.empty();
        
        
    }
    
    神仙般的做法，，一个二叉树，可以发现空节点的个数是非空节点的个数+1。  用一个cnt 来统计他们的个数，初始设为空，扫描过程中，发现空节点++,非空节点--. 到最后cnt得变成0，期间如果cnt变成0就return false
    
    bool isValidSerialization(string preorder) {
        
        preorder+=',';
        string t;
        int cnt = 1;
        
        for(int i = 0; i < preorder.size(); ++i) {
            if(preorder[i] == ',') {
                if(cnt == 0) return false;  //表示之前的树已经满了，那你这个点想要加给谁？
                
                if(t != "#") ++cnt;
                else --cnt;
                t = "";
                
            } else {
                t += preorder[i];
            }
        }
        
        return cnt == 0;
    }
};