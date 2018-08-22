//Follow up for "Unique Paths":
//
//Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//For example,
//There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
//[
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
//]
//The total number of unique paths is 2.
//
//Note: m and n will be at most 100.


//和I思路几乎一样,之要看到obstacle 填0就好了，否则还是用一样的递推公式。

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        obstacleGrid[0][0] =  obstacleGrid[0][0]? 0:1;
        for(int i = 1; i < obstacleGrid[0].size(); ++i) {
            obstacleGrid[0][i] = obstacleGrid[0][i] ? 0: obstacleGrid[0][i-1];
        }
        
        for(int i = 1; i < obstacleGrid.size(); ++i) {
            obstacleGrid[i][0] = obstacleGrid[i][0] ? 0: obstacleGrid[i-1][0];
        }
        
        for(int i = 1; i < obstacleGrid.size(); ++i) {
            for(int j = 1; j < obstacleGrid[0].size(); ++j) {
                obstacleGrid[i][j] = obstacleGrid[i][j] ? 0: obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid.back().back();
    }
    
    下面运用了O(n)空间，特别是第一行和第一列以及第一个点很容易出错。。
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(!obstacleGrid.size() || !obstacleGrid[0].size()) return 0;
        
        vector<int> dp(obstacleGrid[0].size(),1);
        
        for(int i = 0; i < obstacleGrid.size(); ++i) {
            for(int j = 0; j < obstacleGrid[0].size(); ++j) {
                if(j == 0) dp[j] = obstacleGrid[i][j] == 1? 0: dp[j];
                else if(i == 0) dp[j] = obstacleGrid[i][j] == 1? 0 : dp[j-1];
                else dp[j] = obstacleGrid[i][j] == 1? 0:  dp[j] + dp[j-1];
            }
        }
        
        return dp.back();
    }
};