//You are given a m x n 2D grid initialized with these three possible values.
//
//-1 - A wall or an obstacle.
//0 - A gate.
//INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
//Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
//
//For example, given the 2D grid:
//INF  -1  0  INF
//INF INF INF  -1
//INF  -1 INF  -1
//  0  -1 INF INF
//After running your function, the 2D grid should be:
//  3  -1   0   1
//  2   2   1  -1
//  1  -1   2  -1
//  0  -1   3   4

//dfs,从每一个出口开始比较简单一点，每一次访问时，如果depth小于当前值，就覆盖 。 关键一点是如何判断每一次dfs是否已经访问过？ 我们可以发现如果当前值已经<=depth值了，就可以退出了，因为说明之前dfs过，最小值不会再变化。

class Solution {
public:
    
    void bfs(int i, int j, vector<vector<int>>& rooms, int depth) {
        if(i < 0|| i >= rooms.size() || j < 0 || j >= rooms[0].size() ||rooms[i][j] == -1 ||(depth&&depth >= rooms[i][j])) return;
        
        rooms[i][j] = depth;

        bfs(i-1,j,rooms,depth+1);
        bfs(i,j-1,rooms,depth+1);
        bfs(i+1,j,rooms,depth+1);
        bfs(i,j+1,rooms,depth+1);
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        for(int i = 0; i < rooms.size(); ++i) {
            for(int j = 0; j < rooms[0].size(); ++j) {
                if(rooms[i][j] == 0) {
                    bfs(i,j,rooms,0);
                }
            }
        }
    }
};