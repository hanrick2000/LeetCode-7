//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//Some examples:
//  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


//从左到右扫描逆波兰式，遇到操作数压栈，遇到操作符就弹出两个数运算，把结果压栈，注意双目操作符是栈弹出的第二个数做被操作数（被除数，被减数，等等）。

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> operands;
        
        for(auto &x: tokens) {
            if(x=="+"||x=="-"||x=="*"||x=="/") {
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                
                if(x== "+") a+=b;
                if(x=="-") a-=b;
                if(x=="*") a*=b;
                if(x=="/") a/=b;
                
                operands.push(a);
                
            }
            else {
                operands.push(stoi(x));
            }
        }
        
        return operands.top();
    }
};