//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
//For example, given the following matrix:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 4.

//这题的动态规划公式很简单，但不容易一下子出来，设dp[i][j]是maxi[i][j]为右下角的最大正方形的边长， 公式dp[i][j] = maxi[i][j] == 1? 1+min(maxi[i-1][j-1], maxi[i-1][j],maxi[i][j-1])  :0;
//
//注意长或宽为1的case.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(!matrix.size()||!matrix[0].size()) return 0;
        
        int maxi = 0;
        
        for(int i = 0; i < matrix.size(); ++i) {
            maxi = max(maxi,matrix[i][0] - '0');
        }
        
        for(int i = 1; i < matrix[0].size(); ++i) {
            maxi = max(maxi,matrix[0][i] - '0');
        }
        
        for(int i = 1; i < matrix.size(); ++i) {
            for(int j = 1; j < matrix[0].size(); ++j) {
                if(matrix[i][j]-'0') {
                    matrix[i][j] = 1+min(min (matrix[i-1][j-1],matrix[i-1][j]),matrix[i][j-1]);
                    maxi = max(maxi,matrix[i][j]-'0');
                }
            }
        }
        
        return maxi*maxi;
        
    }
};