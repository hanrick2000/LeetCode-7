//Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
//The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
//Note that you can only put the bomb at an empty cell.
//
//Example:
//For the given grid
//
//0 E 0 0
//E 0 W E
//0 E 0 0
//
//return 3. (Placing a bomb at (1,1) kills 3 enemies)

这题动态规划的思想是，  从i列开始，自上而下统计每一个空点位置能炸到的上面的敌人数，从下而上统计每一个空点位置能炸到的下面的敌人数。然后对每一行也做类似的处理。需要O(m*n)的空间 时间也是O(m*n)

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        
        if(!grid.size() || !grid[0].size()) return 0;
        
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size()));
        
        int res = 0;
        
        for(int i = 0; i < grid.size(); ++i) {
            
            int t = 0;
            
            for(int j = 0; j < grid[0].size(); ++j) {
                
                if(grid[i][j] == 'E') ++t;
                else if(grid[i][j] == 'W') t = 0;
                else {
                    dp[i][j] += t;
                    // res = max(res,dp[i][j]);
                }
            }
        }
        for(int i = 0; i < grid.size(); ++i) {
            
            int t = 0;
            
            for(int j = grid[0].size() - 1; j >= 0; --j) {
                
                if(grid[i][j] == 'E') ++t;
                else if(grid[i][j] == 'W') t = 0;
                else {
                    dp[i][j] += t;
                    // res = max(res,dp[i][j]);
                }
            }
        }
        
        
        for(int i = 0; i < grid[0].size(); ++i) {
            
            int t = 0;
            
            for(int j = 0; j < grid.size(); ++j) {
                
                if(grid[j][i] == 'E') ++t;
                else if(grid[j][i] == 'W') t = 0;
                else {
                    dp[j][i] += t;
                    // res = max(res,dp[j][i]);
                }
            }
        }
        for(int i = 0; i < grid[0].size(); ++i) {
            
            int t = 0;
            
            for(int j = grid.size() - 1; j >= 0; --j) {
                
                if(grid[j][i] == 'E') ++t;
                else if(grid[j][i] == 'W') t = 0;
                else {
                    dp[j][i] += t;
                    res = max(res,dp[j][i]);
                }
            }
        }
        return res;
    }
};