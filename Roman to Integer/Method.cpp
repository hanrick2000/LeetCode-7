//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.

//找到规律即可，对于C,X,I有时会做左边的字母，还需要额外判断他在左边的情形，这时两个字母一起处理即可。一定要小心 当i在一个if里面会更改时，外面一定要用if else if.

class Solution {
public:
    int romanToInt(string s) {
        
        int res = 0;
        
        for(int i = 0; i < s.size(); ++i) {
            
            if(s[i] == 'M') res+=1000;
            
            else if(s[i] == 'C') {
                
                if(i==s.size()) {
                    res+=100;
                    return res;
                }
                
                else if(s[i+1] == 'M') {
                    res+=900;
                    ++i;
                }
                    
                else if(s[i+1] == 'D') {
                    res+=400;
                    ++i;
                }
                    
                else {
                    res+=100;
                }
            }
            
            else if(s[i] == 'D') {
                res+=500;
            }
            
            else if(s[i] == 'X') {
                if(i==s.size()) {
                    res+=10;
                    return res;
                }
                
                else if(s[i+1] == 'C') {
                    res+=90;
                    ++i;
                }
                else if(s[i+1] == 'L') {
                    res+=40;
                    ++i;
                }
                    
                else {
                    res+=10;
                }
            }
            
            else if(s[i] == 'L') {
                res+=50;
            }

            else if(s[i] == 'I') {
                if(i==s.size()) {
                    res+=1;
                    return res;
                }
                
                else if(s[i+1] == 'X') {
                    res+=9;
                    ++i;
                }
                else if(s[i+1] == 'V') {
                    res+=4;
                    ++i;
                }
                    
                else {
                    ++res;
                }
            }
            
            else if(s[i] == 'V') {
                res+=5;
            }
        }
        
        return res;
    }
};