//You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
//
//Each 0 marks an empty land which you can pass by freely.
//Each 1 marks a building which you cannot pass through.
//Each 2 marks an obstacle which you cannot pass through.
//For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):
//
//1 - 0 - 2 - 0 - 1
//|   |   |   |   |
//0 - 0 - 0 - 0 - 0
//|   |   |   |   |
//0 - 0 - 1 - 0 - 0
//The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

//从所有的建筑开始BFS， 计算叠加到空地上的和，还得计算每一个空地有多少建筑能够到达。如果空地最后能够到达的建筑数目少于总共的建筑数目，返回-1.

class Solution {
public:


    void bfs(const vector<vector<int>>& grid, int i, int j, vector<vector<int>>& grid2, vector<vector<int>>& grid3) {
        
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(),false));
            
        queue<pair<int,int>> que;
        
        que.push(make_pair(i,j));
        
        int level = 0;
        
        while(que.size()) {
            
            int len = que.size();
            
            for(int i = 0; i < len; ++i) {
                
                pair<int,int> tmp = que.front();
                
                que.pop();
                
                int i1 = tmp.first, j1 = tmp.second;
                
                grid2[i1][j1] += level;
                grid3[i1][j1] ++;
                
                if(i1 > 0 && !visited[i1-1][j1] && grid[i1-1][j1] == 0) {
                    que.push(make_pair(i1-1,j1));
                    visited[i1-1][j1] = true;    
                }
                
                if(j1 > 0 && !visited[i1][j1-1] && grid[i1][j1-1] == 0) {
                    que.push(make_pair(i1,j1-1));
                    visited[i1][j1-1] = true;     
                }
                
                if(i1 < grid.size()-1 && !visited[i1+1][j1] && grid[i1+1][j1] == 0) {
                    que.push(make_pair(i1+1,j1));
                    visited[i1+1][j1] = true; 
                }
                
                if(j1 < grid[0].size()-1 && !visited[i1][j1+1] && grid[i1][j1+1] == 0) {
                    que.push(make_pair(i1,j1+1));
                    visited[i1][j1+1] = true; 
                }
            }

            ++level;
            
        }
    
        return ;
        
    }

    int shortestDistance(vector<vector<int>>& grid) {
        
        vector<vector<int>> grid2 = grid, grid3 = grid;
        
        
        int num = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                
                if(grid[i][j] == 1) {
                    bfs(grid, i, j, grid2, grid3);
                    ++num;
                }
                
            }
        }

        int res = INT_MAX;
      
        
     
        for(int i = 0; i < grid2.size(); ++i) {
            for(int j = 0; j < grid2[0].size(); ++j) {
                
                if(grid[i][j] == 0 && grid3[i][j] == num) {
                    if(grid2[i][j] < res) {
                        res = grid2[i][j];
                    }
                }
            }
        }
  
        
        if(res == INT_MAX) return -1;
        
        
        return res;
        
    }
};