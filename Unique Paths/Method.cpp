//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
//How many possible unique paths are there?
//
//
//Above is a 3 x 7 grid. How many possible unique paths are there?
//
//Note: m and n will be at most 100.


//典型的动态规划题，实际上也就是求组合数，按照公式来会有一大堆阶乘，很容易溢出，不推荐，不放妨就安装
//递推公式来，实际也正好是杨辉三角的公式，时间空间都为O(m*n)。


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> unit(n);
        vector<vector<int>> opt(m,unit);
        
        opt[0][0] = 1;
        
        for(int i = 1; i < n; ++i) {
            opt[0][i] = opt[0][i-1];
        }
        
        for(int i = 1; i < m; ++i) {
            opt[i][0] = opt[i-1][0];            
        }
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                opt[i][j] = opt[i-1][j] + opt[i][j-1];
            }
        }
        return opt[m-1][n-1];
    }
};