//A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given an encoded message containing digits, determine the total number of ways to decode it.
//
//For example,
//Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
//The number of ways decoding "12" is 2.

//
//显然动态规划，不过要考虑太多情况  100, 20, 130,等


class Solution {
public:
    int numDecodings(string s) {
        
        if(s=="") return 0;
        
        vector<int> num = {1};
        
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '0' && (i<1||s[i-1]>'2'||s[i-1] == '0')) return 0;
            
            if(i == 0) {
                num.push_back(1);
            }
            
            else {
                if(s[i]-'0' + (s[i-1]-'0')*10>26||s[i-1]=='0') {
                    num.push_back(num.back());
                }
                else {
                    if(s[i] == '0')
                        num.push_back(num[i-1]);
                    else {
                        num.push_back(num[i-1]+num[i]);    
                    }
                }
                
            }
            
        }

        return num.back();
        
    }
};