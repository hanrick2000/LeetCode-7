这个做法是针对+-*/没有括号的特殊例子。用一个操作数栈。顺序扫描下来，保存上一个符号，遇到一个数后，如果上一个符号是+/-，存放结果进去(+number/-number),如果是*//,把操作数栈的第一个数拿出来，与当前数进行相应的操作，再把结果放进栈去。
最后把栈里面所有的数加起来。

class Solution {
public:
    int calculate(string s) {
        // stack<char> operatorStack;
        stack<int> operands;
        
        int tmp = 0;
        
        char c = '+';
        
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') continue;
            
            if(s[i]>='0'&&s[i]<='9') {
                tmp = 0;
                while(i<s.size()&&s[i]>='0'&&s[i]<='9') {
                    tmp = tmp*10 + s[i++]-'0';
                }
                --i;
                
                if(c == '+') {
                    operands.push(tmp);
                }
                else if(c=='-') {
                    operands.push(-tmp);
                }
                else if(c == '*') {
                    int a = operands.top();
                    operands.pop();
                    operands.push(a*tmp);
                }
                else {
                    int a = operands.top();
                    operands.pop();
                    operands.push(a/tmp);
                }
            }

            
            else {  //'+', '-', '*' or '/'
                c = s[i];
  
            }
        }
        
        int res = 0;
        
        while(operands.size()) {
            
            res+=operands.top();
            
            operands.pop();
            
        }
        
        
        return res;
    }
};