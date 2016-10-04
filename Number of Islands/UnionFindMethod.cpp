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

//union-find 做法通常有以下三步，makeset, 把parent数组和size数组初始化。
//2，union ， 3.计数。
//这道题也一样，先把二维平面上的点对到一维数组上去，然后对于所有为1的点对右边和下面的1进行并集union操作。最后统计1时我们就看那些grid==1并且parent == 自己的点的个数，因为合并到最后总有一个根节点满足parent==自己。
//统计也可以直接通过union find里面的更新count函数来，只要每次找到一个1，之前就++count，然后每次union成功都--count.
    
    
class Solution {

public:

     //查找，并伴随有路径压缩  
     int findSet(int x, vector<int> &father)  {  
         if (father[x]!=x)  {  
             father[x]=findSet(father[x], father);  
         }  
         return father[x];  
     }  
       
     //合并，修改num的值  
     void Union(vector<int> &father, vector<int> &size ,int a,int b, int &total)  {  
         
         int x=findSet(a,father);  
         int y=findSet(b,father);  
         
         if (x==y)  {  
             return ;  
         }  
         
         if (size[x]<=size[y]) {  
             father[x]=y;  
             size[y]+=size[x];  
         }  
         
         else  {  
             father[y]=x;  
             size[x]+=size[y];  
         }  
         --total;
     }  

    int numIslands(vector<vector<char>>& grid) {
        
        if(!grid.size() || !grid[0].size()) return 0;
        
        vector<int> father(grid.size()*grid[0].size(),-1);
        
        vector<int> size(grid.size()*grid[0].size(),1);
        
        int total = 0;
        
        for(int i = 0; i < grid.size(); ++i) {    //初始化
            for(int j = 0; j < grid[0].size(); ++j) {
                int index = i*grid[0].size() + j;
                father[index] = index;
            }
        }
    
        for(int i = 0; i < grid.size(); ++i) {   //union find 
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j]=='1') {
                    ++total;
                    int index = i*grid[0].size() + j;
                    if(i + 1 < grid.size() && grid[i+1][j] == '1')  {
                        Union(father, size, index, index+grid[0].size(),total);
                    }
                    if(j + 1 < grid[0].size() && grid[i][j+1] == '1') {
                        Union(father, size, index, index+1, total);
                    }
                }
            }
        }
        
        return total;
    }
};