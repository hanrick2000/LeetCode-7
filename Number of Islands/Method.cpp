//Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//11110
//11010
//11000
//00000
//Answer: 1
//
//Example 2:
//
//11000
//11000
//00100
//00011
//Answer: 3

看见‘1’dfs深搜，把看见的陆地全部变成海洋。控制一个计数器计数。

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!='1') return;
        
        grid[i][j] = '0';
           
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        if(!grid.size()||!grid[0].size()) return 0;
        
        int res = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++res;
                }
            }
        }
        
        return res;
    }
    
    下面是bfs的做法。。
    
    void bfs(vector<vector<char>>& grid, int i, int j) {
       
        queue<pair<int,int>> myque;
        myque.push({i,j});
        grid[i][j] = '0';
        
        while(myque.size()) {
            pair<int,int> tmp = myque.front();
            myque.pop();
            int i1 = tmp.first, j1 = tmp.second;
            
            if(i1 > 0 && grid[i1-1][j1] == '1') {
                myque.push({i1-1, j1});
                grid[i1-1][j1] = '0';
            }
            if(i1 < grid.size()-1 && grid[i1+1][j1] == '1') {
                myque.push({i1+1, j1});
                grid[i1+1][j1] = '0';
            }
            if(j1 > 0 && grid[i1][j1-1] == '1') {
                myque.push({i1,j1-1});
                grid[i1][j1-1] = '0';
            }
            if(j1 < grid[0].size()-1 && grid[i1][j1+1] == '1') {
                myque.push({i1,j1+1});
                grid[i1][j1+1] = '0';
            }
        }

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size() || !grid[0].size()) return 0;
        int res = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    bfs(grid, i,j);
                    ++res;
                }
            }
        }
        return res;
    }
};