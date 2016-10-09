// (注意是substring)   这题动态规划，二维数组dp[i][j] 表示a[0...i] 到b[0...j]以a[i]和b[j]为结尾的最长common substring. 所以dp[i][j] == s[i] == s[j] ?  dp[i-1][j-1] +1, 0; 最后用一个全局变量记录每一个dp的最大值。时间 空间 O（mn)


class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {

        vector<vector<int>> dp(A.size()+1, vector<int> (B.size()+1));
        int res = 0;
        
        for (int i = 1; i < dp.size(); ++i) {
            for(int j = 1; j < dp[0].size(); ++j) {
                if(A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        
        return res;
    }
};
