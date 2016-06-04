//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.



//用栈做，右括号出栈  左括号进栈，switch 语句很奇怪通过不了，就丑陋地运用了if-else


class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        
        for(auto &x: s) {
            if(x == '('||x=='['||x=='{') mystack.push(x);
            
            else {
                if(!mystack.size()) return false;

                if(mystack.top() == '('&&x!=')') return false;
                if(mystack.top() == '['&&x!=']') return false;
                if(mystack.top() == '{'&&x!='}') return false;
                
                mystack.pop();
            }
        }
        
        return mystack.empty();
    }
};