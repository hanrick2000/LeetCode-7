//A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//Example:
//
//Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
//Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
//
//0 0 0
//0 0 0
//0 0 0
//Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
//
//1 0 0
//0 0 0   Number of islands = 1
//0 0 0
//Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
//
//1 1 0
//0 0 0   Number of islands = 1
//0 0 0
//Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
//
//1 1 0
//0 0 1   Number of islands = 2
//0 0 0
//Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
//
//1 1 0
//0 0 1   Number of islands = 3
//0 1 0
//We return the result as an array: [1, 1, 2, 3]

//还是并查集用的熟不熟。得路径压缩 按秩合并。
    
//    注意合并时，一定要记得是两个参数的root进行合并，光改自己没用.
//还得记得root 是怎么更新count的。

class Solution {
public:

    int findParent(int x, vector<int> &parent) {
        
        if(parent[x] == x) return x;
        
        parent[x] = findParent(parent[x],parent);
        
        return parent[x];
    }
  
    void Union(int x, int y, vector<int> & parent, vector<int> & sz, int &total) {
    
        int x1 = findParent(x,parent);
        int y1 = findParent(y,parent);

        if(x1==y1) return;
        
        if (sz[x1] < sz[y1]) { 
            parent[x1] = y1;   //注意一定是x,y的root在赋值  不是x,y
            sz[x1] += sz[y1]; 
        }
        else { 
            parent[y1] = x1;
            sz[y1] += sz[x1]; 
        }
        
        --total;
    }
 
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        
        vector<int> res;
        
        vector<int> parent(m*n,0);
        vector<int> size(m*n,1);
        vector<bool> land(m*n,0);
        
        for(int i = 0; i < parent.size(); ++i) parent[i] = i;
        
        int total = 0;
        
        for(auto pos: positions) {
            
            ++total;
            
            int index = pos.first*n + pos.second;
            
            land[index] = true;
            
            if(pos.second && land[index-1]) {
                Union(index, index-1, parent, size, total);
            }
            
            if(pos.second < n - 1 && land[index+1]){
                Union(index, index+1, parent, size, total);
            }
            
            if(pos.first && land[index-n]) {
                Union(index, index-n, parent, size, total);
            }
            
            if(pos.first < m - 1 && land[index+n]){
                Union(index, index+n, parent, size, total);
            }
            
            res.push_back(total);
        }
        
        return res;
    }
};