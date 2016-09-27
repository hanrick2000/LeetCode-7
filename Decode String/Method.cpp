//Given an encoded string, return it's decoded string.
//
//The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//
//You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
//
//Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
//
//Examples:
//
//s = "3[a]2[bc]", return "aaabcbc".
//s = "3[a2[c]]", return "accaccacc".
//s = "2[abc]3[cd]ef", return "abcabccdcdcdef".


//这题楞是把它当成了  括号四则运算  那样做，维护两个栈，第一个是操作数栈存数字，第二个是符号栈，存纯string和[]。只要有数字就入栈，只要有[就入栈，只要有字符就和栈顶的字符（非[）叠加，只要遇到]就拿出操作数和操作字符串进行复制，然后弹出[。
//最后把栈里面的字符串拼起来

class Solution {
public:
    string decodeString(string s) {
        if(s=="") return "";
        
        stack<int> num;
        stack<string> token;
        
        string res;
        
        int n = 0;
        string tmp;
        
        for(int i = 0; i < s.size(); ++i) {
            if(s[i]>='0'&&s[i]<='9') {
                
                while(i<s.size()&&s[i]>='0'&&s[i]<='9') n= n*10 + s[i++]-'0';
                num.push(n);
                n=0;
                --i;

            }
            
            else if(s[i] == '[') {
                token.push("[");
            }
            
            else if(s[i] == ']') {
                
                string t;
               
                int len =  num.top();
                
                for(int j = 0; j < len; ++j) {
                    t += token.top();
                }

                num.pop();
                token.pop();
                token.pop();
                
                if(token.size()&&token.top()!="[") {
                    token.top()+=t;
                }
                else {
                    token.push(t);
                }
                
            }
            else {
                if(token.size()&&token.top()!="[") token.top()+=s[i];
                
                else {
                    string t; 
                    t+= s[i];
                    token.push(t);
                }

            }

        }
        
        while(token.size()!=1) {
            string t = token.top();
            token.pop();
            token.top() += t;
        }
        
        
        return token.top();
        
        
    }

};