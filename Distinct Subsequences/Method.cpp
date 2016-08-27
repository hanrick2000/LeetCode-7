//Given a string S and a string T, count the number of distinct subsequences of T in S.
//
//A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//Here is an example:
//S = "rabbbit", T = "rabbit"
//
//Return 3.


//用一个二维数组opt[i][j], 表示numDistinct(s[0:i]，t[0:j]).
    
// opt[i][j] = if s[i-1] == t[j-1] (opt[i-1][j]+opt[i-1][j-1]) else opt[i-1][j]  因为如果最后一个字符一样，那么这个s的这个字符可以选择匹配t的最后这个字符，种类数等同于opt[i-1][j-1],也可以不匹配，种类数等同于opt[i-1][j]. 如果一样，只能不必配，等同于opt[i-1][j].然后做好base case.

//当然也可以每一次只保留 opt[i-1]和opt[i], 只用O(2*n)空间，但每一次得重新复制数组。算法意义并不是特别大／

class Solution {
public:
    int numDistinct(string s, string t) {
        
        //s = "rabbbit" t = "rabbit"   opt[4][3] 表示  numDistinct("rabb","rab")
        
        // opt[i][j] = if s[i-1] == t[j-1] (opt[i-1][j]+opt[i-1][j-1]) else opt[i-1][j]
        // opt[0][1] ,[0][2],...[0][n] = 0
        // opt[0][0] = 1
        // opt[1][0] = 1 [2][0]... [n][0] = 1      opt[2][1]   "ra"   "r"
        
        vector<vector<int>> opt(s.size()+1,vector<int>(t.size()+1));
        
        
        for(int i = 0; i < opt.size(); ++i) {
            opt[i][0] = 1;
        }
        

        
        for(int i = 1; i < opt.size(); ++i) {
            for(int j = 1; j < opt[0].size(); ++j) {
                opt[i][j] = opt[i-1][j];
                if(s[i-1] == t[j-1]) {
                    opt[i][j] += opt[i-1][j-1];
                }

            }
        }
        
        return opt.back().back();
        
        
        
    }
};