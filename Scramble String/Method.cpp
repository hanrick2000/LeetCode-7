//Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
//
//Below is one possible representation of s1 = "great":
//
//    great
//   /    \
//  gr    eat
// / \    /  \
//g   r  e   at
//           / \
//          a   t
//To scramble the string, we may choose any non-leaf node and swap its two children.
//
//For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
//
//    rgeat
//   /    \
//  rg    eat
// / \    /  \
//r   g  e   at
//           / \
//          a   t
//We say that "rgeat" is a scrambled string of "great".
//
//Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
//
//    rgtae
//   /    \
//  rg    tae
// / \    /  \
//r   g  ta  e
//       / \
//      t   a
//We say that "rgtae" is a scrambled string of "great".
//
//Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

//这道题是用dp,  其实还是recursive+memo 更直观一点。
//    
//假设dp[i][j][len] 表示 s1[i...i+len） 与  s2[j...j+len）字符串是否是scramble string，那么状态转移方程：
//                                       
//dp[i][j][len] = ||(dp[i][j][k]&&dp[i+k][j+k][len-k])||(dp[i][j+len-k][k]&&dp[i+len-k][j][len-k])).. 
//即把string a , b 从中间每一个位置劈开，可以a的前面匹配b的前面，a的后面匹配b的后面，也可以a前面匹配b的后面。O(n^3).
                                       

class Solution {
public:
    
    bool isScrambleHelper(string &s1, string &s2, int s1_1, int len, int s2_1, vector<vector<vector<int>>> &dp) {

        if(dp[s1_1][s2_1][len]!=-1) return dp[s1_1][s2_1][len];
        
        if(!len) {
            
            dp[s1_1][s2_1][len] = 1;
            return dp[s1_1][s2_1][len];
        }
      
        if(len == 1) {
            
            dp[s1_1][s2_1][len] = s1[s1_1] == s2[s2_1];
            return dp[s1_1][s2_1][len];
        }
        
        for(int i = 1; i < len; ++i) {

            if(isScrambleHelper(s1, s2, s1_1, i, s2_1, dp)&&isScrambleHelper(s1, s2, s1_1+i, len - i, s2_1+i, dp)||(isScrambleHelper(s1, s2, s1_1, i, s2_1+len-i, dp)&&isScrambleHelper(s1, s2, s1_1+i, len - i, s2_1, dp))) {
                dp[s1_1][s2_1][len] = 1;
                return dp[s1_1][s2_1][len];
            }
        }
        
        dp[s1_1][s2_1][len] = 0;
        return dp[s1_1][s2_1][len];
    }
    
  
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        
        
        int n = s1.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n,vector<int>(n+1,-1)));
        
        return isScrambleHelper(s1,s2,0,n,0,dp);
        
    }
};