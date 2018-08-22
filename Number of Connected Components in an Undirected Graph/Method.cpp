//Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
//
//Example 1:
//     0          3
//     |          |
//     1 --- 2    4
//Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
//
//Example 2:
//     0           4
//     |           |
//     1 --- 2 --- 3
//Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
//
//Note:
//You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

//很显然，dfs,bfs都可以。  选一个dfs做吧。

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        
        if(n==0) return 0;
        
        vector<vector<int>> res(n);
        
        for(auto x: edges) {
            if(x.first!=x.second) {
                res[x.first].push_back(x.second);
                res[x.second].push_back(x.first);
            }
        }
        
        int num = 0;
        
        stack<int> mystack;
        int root = 0;
        vector<bool> visited(n,false);

        do {
            mystack.push(root);
            
            visited[root] = true;
            
            while(mystack.size()) {
                
                int t = mystack.top();
                
                mystack.pop();
                
                for(int i = 0; i < res[t].size(); ++i) {
                    if(!visited[res[t][i]]) {
                        visited[res[t][i]] = true;
                        mystack.push(res[t][i]);
                    }
                }
            }
            
            ++num;
            int i = 0;
            for(; i < n; ++i) {
                if(!visited[i]) {
                    root = i;
                    break;
                }
            }
            
            if(i == n) break;
            
        } while(1);
        
        return num;
    }
    
    class Solution {
public:
    
    int findSet(int x, vector<int> &father) {
        if(x != father[x]) {
            father[x] = findSet(father[x], father);   
        } 
        return father[x];
    }

    void Union(int x, int y, vector<int> &father, vector<int> &size) {
        int xx = findSet(x, father);
        int yy = findSet(y, father);
        
        if(xx == yy) return;
        
        if(size[xx] > size[yy]) {
            father[yy] = xx;
            size[xx] += size[yy];
        }
        else {
            father[xx] = yy;
            size[yy] += size[xx];
        }
        return;
    }

    int countComponents(int n, vector<pair<int, int>>& edges) {
        
        vector<int> father(n);
        vector<int> size(n,1);
        
        for(int i = 0 ; i < n; ++i) father[i] = i;
        
        for(auto &edge: edges) {
            Union(edge.first, edge.second, father, size);
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i) if(father[i] == i) ++cnt;
        return cnt;
    }
};
    
};