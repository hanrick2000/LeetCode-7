//Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.
//
//Note:
//Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
//
//Example:
//
//Given the following 3x6 height map:
//[
//  [1,4,3,1,3,2],
//  [3,2,1,3,2,4],
//  [2,3,3,2,3,1]
//]
//
//Return 4.

似懂非懂，把外面的一层围墙高度放到PQ里，每一次取高度最小的出来bfs, 进过PQ的都标记为true，就算算过接水量了，不用BFS。再维持一个海平面高度，从最小开始，每次海平面高度都为max(QP出来的高度，当前海平面高度)；


struct Node {
    
    int x;
    int y;
    int height;
    Node(int x = 0, int y = 0, int height = 0): x(x), y(y),height(height) {}
};


struct cmp {
    bool operator() (const Node& a, const Node &b) {
        return a.height > b.height;
    }
    
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        if(heightMap.size() <3 || heightMap[0].size() < 3) return 0;
        
        int mx = INT_MIN, res = 0;
        
        vector<vector<int>> visited(heightMap.size(), vector<int> (heightMap[0].size(),0));
        
        priority_queue<Node,vector<Node>, cmp>  pq;
        
        for(int i = 0; i<heightMap.size(); ++i) {
            pq.push(Node(i,0,heightMap[i][0]));
            pq.push(Node(i,heightMap[0].size()-1, heightMap[i][heightMap[0].size()-1]));
            visited[i][0] = 1;
            visited[i][heightMap[0].size()-1] = 1;
        }
        
        
        for(int i = 1; i < heightMap[0].size()-1; ++i) {
            pq.push(Node(0,i,heightMap[0][i]));
            pq.push(Node(heightMap.size()-1,i, heightMap[heightMap.size()-1][i]));
            
            visited[0][i] = 1;
            visited[heightMap.size()-1][i] = 1;
        }

        while(pq.size()) {
            
            Node tmp = pq.top();
            pq.pop();
            
            mx = max(mx,tmp.height);// 什么原理？
            
            int x = tmp.x;
            int y = tmp.y;

            
            if(x&&!visited[x-1][y])  {
                if(heightMap[x-1][y] < mx) {
                    res += mx - heightMap[x-1][y];
                }
                pq.push(Node(x-1,y, heightMap[x-1][y]));
                visited[x-1][y] = 1;
            }
            
            if(x < heightMap.size()-1 &&!visited[x+1][y])  {

                if(heightMap[x+1][y] < mx) {
                    res += mx - heightMap[x+1][y];
                }
                pq.push(Node(x+1,y, heightMap[x+1][y]));
                visited[x+1][y] = 1;
            }
            
            if(y&&!visited[x][y-1])  {
                if(heightMap[x][y-1] < mx) {
                    res += mx - heightMap[x][y-1];
                }
                pq.push(Node(x,y-1, heightMap[x][y-1]));
                visited[x][y-1] = 1;
            }
            
            if(y < heightMap[0].size()-1&&!visited[x][y+1])  {
                if(heightMap[x][y+1] < mx) {
                    res += mx - heightMap[x][y+1];
                }
                pq.push(Node(x,y+1, heightMap[x][y+1]));
                visited[x][y+1] = 1;
            }
            
        }
        
        return res;
        
        
        
    }
};