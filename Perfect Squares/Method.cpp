//Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
//For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

//很简单的DP, 依次减去小的square

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp = {0,1};

        for(int i = 2; i <= n; ++i) {
            
            int mini = i;
            
            for(int j = 2; j*j<=i ; ++j) {
                mini = min(mini, dp[i-j*j]+1);
            }
            
            dp.push_back(mini);
        }
        
        return dp.back();
    }
};


