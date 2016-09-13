//For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
//
//Format
//The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
//
//You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
//
//Example 1:
//
//Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
//
//        0
//        |
//        1
//       / \
//      2   3
//return [1]
//
//Example 2:
//
//Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
//
//     0  1  2
//      \ | /
//        3
//        |
//        4
//        |
//        5
//return [3, 4]
//
//Show Hint 
//Note:
//
//(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
//
//(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

// 这题思路是这样：求出这个图的直径（所有两点之间最远的距离），如何求？先随意从一个点bfs，最远那个点肯定在直径的一端点，在从这个点开始bfs,最远的那个点就是直径的另一个短点。然后bfs记得要记录path,path是反向记录的，有孩子记父亲.最后只要通过这个path往回找一半的距离即可。

class Solution {
public:

    int bfs(const vector<vector<int>> &graph,  int start, int &level, vector<int> &path) {
        queue<int> myque;
        myque.push(start);
        int res;
        level = 0;
        vector<bool> visited(graph.size(),false);
        visited[start] = true;
        
        while(myque.size()) {
            
            ++level;
            int len = myque.size();
            res = myque.front();
            
            for(int i = 0; i < len; ++i) {
                int tmp = myque.front();
                myque.pop();
                for(int j = 0; j < graph[tmp].size(); ++j) {
                    if(!visited[graph[tmp][j]]) {
                        myque.push(graph[tmp][j]);
                        visited[graph[tmp][j]] = true;
                        path[graph[tmp][j]] = tmp;
                    }
                }
                
            }
            
        }
        
        return res;
        
    }
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        
        if(n == 0) return {};
        
        vector<vector<int>> graph(n);
        
        for(int i = 0; i < edges.size(); ++i) {
            int a = edges[i].first, b = edges[i].second;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        
        int level = 0;
        
        vector<int> path(n,-1);
        
        int v = bfs(graph, 0, level, path);
        
        path.resize(n,-1);
        
        int u = bfs(graph, v, level, path);
        int count = 0;
        
        while(1) {
            
            if(level%2&&count == level/2)  {
                return {u};
            }
            
            if(!(level%2)) {
                int x;
                if(count == (level-1)/2) {
                    x = u;
                }
                
                else if(count == level/2) {
                    return {u,x};
                }
                
            }
            
            ++count;
            u = path[u];
        }
        return {};
        
    }
};