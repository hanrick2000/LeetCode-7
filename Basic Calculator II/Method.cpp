//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
//
//You may assume that the given expression is always valid.
//
//Some examples:
//"3+2*2" = 7
//" 3/2 " = 1
//" 3+5 / 2 " = 5
//Note: Do not use the eval built-in library function.

//这种表达式求解是这样的，有一个操作数栈和一个操作符栈。
//然后顺序开始扫描表达式，
//i)遇到操作数肯定要进操作数栈
//ii)遇到左括号'('进操作符栈
//iii)遇到'+','-','*','\''。查看当前操作符栈的栈顶，循环将栈里面的比该运算符等级高的弹出来，再弹出相应操作数进行运算，结果放回操作数栈，注意栈里面与当前符号相同的话也比当前的优先级高，因为要从左到右的顺序运算。直到符号栈空或栈顶比该运算符等级更低或者'('吗，然后再压进栈.
//iii) 遇到')',循环弹出操作符和相应操作数运算直到遇到'(',也把'('弹走。
//最后扫描完毕后，如果符号栈里有东西，全部弹出来运算。最后操作数里存的是结果。


class Solution {
public:
    int calculate(string s) {
        stack<char> operatorStack;
        stack<int> operands;
        
        
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') continue;
            
            if(s[i]>='0'&&s[i]<='9') {
                int tmp = 0;
                while(i<s.size()&&s[i]>='0'&&s[i]<='9') {
                    tmp = tmp*10 + s[i++]-'0';
                }
                --i;
                operands.push(tmp);
            }

            else if(s[i] == '+'||s[i] == '-') {
                while(operatorStack.size()) {

                    char x = operatorStack.top();
                    int b = operands.top();
                    operands.pop();
                    int a = operands.top();
                    operands.pop();
                        
                    if(x== '+') a+=b;
                    if(x== '-') a-=b;
                    if(x== '*') a*=b;
                    if(x== '/') a/=b;
                        
                    operands.push(a);
                        
                    operatorStack.pop();
                    
                }
                
                operatorStack.push(s[i]);
            }
            
            else {  //'*' or '/'
                
                while(operatorStack.size()) {
                    if(operatorStack.top() == '+' || operatorStack.top() == '-') {
                        break;
                    }
                    else {
                        
                        char x = operatorStack.top();
                        int b = operands.top();
                        operands.pop();
                        int a = operands.top();
                        operands.pop();
                        
                        if(x== '*') a*=b;
                        if(x== '/') a/=b;
                        
                        operands.push(a);
                        
                        operatorStack.pop();
                    }
                    
                }
                
                operatorStack.push(s[i]);
                
            }
        }
        
        while(operatorStack.size()) {
            char x = operatorStack.top();
            
            
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            
            if(x== '+') a+=b;
            if(x=='-') a-=b;
            if(x== '*') a*=b;
            if(x== '/') a/=b;
            
            operands.push(a);
            operatorStack.pop();
            
        }
        
        
        return operands.top();
    }
};