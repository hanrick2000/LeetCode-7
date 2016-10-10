//Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
//
//Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
//
//Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
//
//Note:
//The order of returned grid coordinates does not matter.
//Both m and n are less than 150.
//Example:
//
//Given the following 5x5 matrix:
//
//  Pacific ~   ~   ~   ~   ~ 
//       ~  1   2   2   3  (5) *
//       ~  3   2   3  (4) (4) *
//       ~  2   4  (5)  3   1  *
//       ~ (6) (7)  1   4   5  *
//       ~ (5)  1   1   2   4  *
//          *   *   *   *   * Atlantic
//
//Return:
//
//[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

//很显然BFS,DFS. 相当于从太平洋和大西洋两边往中间DFS，反了方向，往高处流淌。设一个visited int 到了之后就置标志位。  大西洋和太平洋都设自己的标志位。

class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& visited, int flag) {
        if(visited[i][j]&flag) return;
        
        visited[i][j] += flag;
        
        if(i && matrix[i-1][j] >= matrix[i][j]) {
           dfs(i-1,j, matrix, visited, flag);
        }
        
        if(i < matrix.size()-1 && matrix[i+1][j] >= matrix[i][j]) {
           dfs(i+1,j, matrix, visited, flag);
        }
        if(j && matrix[i][j-1] >= matrix[i][j]) {
           dfs(i,j-1, matrix, visited, flag);
        }
        if(j < matrix[0].size()-1 && matrix[i][j+1] >= matrix[i][j]) {
           dfs(i,j+1, matrix, visited, flag);
        }
        
        return;
    }

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        if(matrix.empty() || matrix[0].empty()) return {};
        
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(),0));
        
        vector<pair<int,int>> res;
        
        for(int i = 0; i < matrix.size(); ++i) {
            dfs(i,0,matrix,visited,1);
        }
        
        for(int i = 1; i < matrix[0].size(); ++i) {
            dfs(0,i,matrix,visited,1);
        }
        
        for(int i = 0; i < matrix.size(); ++i) {
            dfs(i,matrix[0].size()-1,matrix,visited,2);
        }
        
        for(int i = 0; i < matrix[0].size(); ++i) {
            dfs(matrix.size()-1,i,matrix,visited,2);
        }
        
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0 ; j < matrix[0].size(); ++j) {
                if(visited[i][j] == 3) res.push_back({i, j});
            }
        }
        
        return res;
    }
};