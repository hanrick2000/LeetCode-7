//该方法从串中每一个字符开始左右两边扩张，依照左右两边字符是否相等，基础条件为所有的单字符（默认回文）和两个字符（两相邻字符相等才行）。
//时间O(n^2) 空间O(1)


class Solution {
public:
    string longestPalindrome(string s) {
        
        int max = 0;
        string maxStr;
        
        for(int i = 0; i < s.size(); ++i) {
            
            int j = 1;
            
            while(i-j>=0&&i+j<s.size()&&s[i-j]==s[i+j]) {
                j++;
            }
            
            if((j<<1)-1>max) {
                max = (j<<1)-1;
                maxStr = s.substr(i-j+1,max);
            }
        }
        
        for(int i = 0; i < s.size()-1; ++i) {
            if(s[i]==s[i+1]) {
                int j = 1;

                while(i-j>=0&&i+1+j<s.size()&&s[i-j]==s[i+1+j]) {
                    j++;
                }
                
                if((j<<1)>max) {
                    max = j<<1;
                    maxStr = s.substr(i-j+1,max);
                }
            }
        }
        
        return maxStr;
        
    }
};