//Given an integer matrix, find the length of the longest increasing path.
//
//From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
//
//Example 1:
//
//nums = [
//  [9,9,4],
//  [6,6,8],
//  [2,1,1]
//]
//Return 4
//The longest increasing path is [1, 2, 6, 9].
//
//Example 2:
//
//nums = [
//  [3,4,5],
//  [3,2,6],
//  [2,2,1]
//]
//Return 4
//The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

这题关键是dfs配合dp.设一个dp矩阵，标记相应的点的lingest increasing path的值，初始设为0(因为最小是1)，然后两重循环，对所有的点dfs，但是如何保证不走回头路？我们发现只要一个点被访问过,dp矩阵肯定已经记下了它的longest increasing path个数，而且这个值不会再改变，所以可以用dp值来防止重复访问。
O(n^2).

class Solution {
public:

    void dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &dp) {
        
        if(dp[i][j]) return;
        
        dp[i][j] = 1;
        
        if(i && matrix[i-1][j] > matrix[i][j]) {

            dfs(matrix, i-1, j, dp);
            
            dp[i][j] = max(dp[i][j], 1 + dp[i-1][j]);

        }
        
        if(j && matrix[i][j-1] > matrix[i][j]) {

            dfs(matrix, i, j-1, dp);
            
            dp[i][j] = max(dp[i][j], 1 + dp[i][j-1]);

        }
        
        if(i < matrix.size()-1 && matrix[i+1][j] > matrix[i][j]) {

            dfs(matrix, i+1, j, dp);
            
            dp[i][j] = max(dp[i][j], 1 + dp[i+1][j]);

        }
        
        if(j < matrix[0].size()-1 && matrix[i][j+1] > matrix[i][j]) {

            dfs(matrix, i, j+1, dp);
            
            dp[i][j] = max(dp[i][j], 1 + dp[i][j+1]);
            
        }
        
        return;
    }


    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        if(!matrix.size() || !matrix[0].size()) return 0;
        
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(),0));
        
        int res = 0;
        
        for(int i = 0; i < matrix.size(); ++i) {
            
            for(int j = 0; j < matrix[0].size(); ++j) {
                
                if(dp[i][j]) continue;
                
                dfs(matrix, i, j, dp);
            }
        }
      
        for(auto x: dp) {
           
            for(auto y: x) {
           
                res = max(res, y);
           
            }
        }
        
        return res;
        
    }
};
