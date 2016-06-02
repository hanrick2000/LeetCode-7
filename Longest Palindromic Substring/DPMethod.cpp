//该方法是基于动态规划的算法，基本原理如下： 
//假设map[p][q] = true表示从s[p]到s[q]之间（含端点）是回文串，那么有如下递推公式：
//map[p-1][q+1] = map[p][q]&&s[p-1]==s[q-1] 很简单。
//然后base case是 所有map[i][i] = true. map[i][i+1] = s[i] == s[i+1]
//这样痛过填充这样一个二维矩阵即可。使劲复杂度和空间复杂度   均为  O(n^2).


class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s == "") return "";
        bool map[1000][1000];  //S的最大长度
        
        for(int i=0; i < s.size();++i) {
            
            map[i][i] = true;
        }
        
        int left=0, length=1;
        
        for(int i=0; i < s.size()-1;++i) {
            
            map[i][i+1] = s[i] == s[i+1];
            if(map[i][i+1]) {
                left = i;
                length = 2;
            } 
        }
        
        for(int len = 2; len < s.size(); ++len) {
            for(int i = 0; i < s.size()-len; ++i) {
                map[i][i+len] = map[i+1][i+len-1]&&s[i] == s[i+len];
                if(map[i][i+len]) {
                    left = i;
                    length = len+1;
                }
            }
        }
                
        return s.substr(left, length);
      
    }
};
