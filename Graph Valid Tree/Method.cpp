//Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
//
//For example:
//
//Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
//
//Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
//
//Hint:
//
//Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
//According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”


//bfs/dfs怎么判断有没有环，这是个问题，但这题判断是不是树?  首先就按照bfs访问，最后看看所有点是不是访问过，都访问过返回边的个数是不是n-1.


class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        
        if(n<2) return true;    // 空图 和 单点都是树
        if(!edges.size()) return false;   //否则就没有连通图
        
        vector<vector<int>> graphList(n);
        
        for(int i = 0; i < edges.size(); ++i) {
            int a = edges[i].first, b = edges[i].second;
            if(a == b) return false;   //自环不允许
            graphList[a].push_back(b);
            graphList[b].push_back(a);  
        }
        
        vector<bool> visited(n);   //防止bfs时死循环，得记录那些节点进过队列。
        
        if(!graphList[0].size()) return false;  //从第一个节点0开始访问,如果0没有边肯定不行
        
        queue<int> myque;
        myque.push(0);
        visited[0] = true;
        
        while(myque.size()) {   //标准的dfs
            int tmp = myque.front();
            myque.pop();
            
            for(int i = 0; i < graphList[tmp].size(); ++i) {
                
                if(visited[graphList[tmp][i]]) continue;
                
                visited[graphList[tmp][i]] = true;   //千万记得判断有没有访问过是加在这里，即延展该点时，就将所有的孩子设为true，而不应该在每一次访问节点时，仅仅设改点为true，记住标记有没有访问过是指有没有进队列。
                myque.push(graphList[tmp][i]);
                
            }
            
        }
        
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) return false;
        }
        
        return edges.size() == n-1;
        
    }
};