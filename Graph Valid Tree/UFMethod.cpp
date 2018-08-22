class Uf {
    vector<int> parent;
    vector<int> size;
    int n;
public:
    Uf(int n): parent(n), size(n,1), n(n) {
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findSet(int x) {
        if(x != parent[x]) {
            parent[x] = findSet(parent[x]);
        }
        return parent[x];
    }
    
    void Union(int a, int b) {
        int x = findSet(a), y = findSet(b);
        if(x == y) return;
        
        if(size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
        --n;
        return;
    }
    
    int component() {
        return n;
    }
};


class Solution {
public:

    bool validTree(int n, vector<pair<int, int>>& edges) {
        
        if(edges.size()!=n-1) return false;
        
        Uf uf(n);

        for(int i = 0; i < edges.size(); ++i) {
            int a = edges[i].first, b = edges[i].second;
            if(a == b) return false;
            uf.Union(a,b);
        }

        return uf.component() == 1;
    }
};