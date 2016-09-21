该图包含了DAG中产生一个source到一个sink的所有path.

class Graph {
    
//    vector<int> vertice;
    vector<vector<int>> edges;
    int num;
    
    void generatePath(int source, int sink, vector<vector<int>> & res, vector<int> &cur, vector<vector<int>> &path);

public:
    
    Graph(int n = 0): num(n), edges(n,{}) {}
    
    void addEdge(int from, int to);
    
    void printGraph();
    
    vector<vector<int>> shortestPath(int source, int sink);
    
};


void Graph::addEdge(int from, int to) {
    
    edges[from].push_back(to);
    
}


vector<vector<int>> Graph::shortestPath(int source, int sink) {
    
    vector<vector<int>> path(num);
    vector<vector<int>> res;
    stack<int> mystack;
    vector<bool> visites(num);
    
    mystack.push(source);
    visites[source] = true;
    
    while (mystack.size()) {
        
        int cur = mystack.top();
        mystack.pop();
        
        for (auto x: edges[cur]) {
            path[x].push_back(cur);
            if (!visites[x]) {
                mystack.push(x);
                visites[x] = true;
            }
        }
        
    }
    
    vector<int> cur;
    cur.push_back(sink);
    
    generatePath(source, sink, res, cur, path);
    
    return res;
    
}


void Graph::generatePath(int source, int sink, vector<vector<int>> & res, vector<int> &cur, vector<vector<int>> &path) {
    
    if(source == sink) {
        
//        cur.push_back(sink);
        reverse(cur.begin(), cur.end());
        
        res.push_back(cur);
        reverse(cur.begin(), cur.end());
        return;
    }
    
    for(auto x: path[sink]) {
        
        cur.push_back(x);
        
        generatePath(source, x, res, cur, path);
        
        cur.pop_back();
    }
}

void Graph::printGraph() {
    
    for (int i = 0; i < edges.size(); ++i) {
        cout<<"节点"<<i<<" "<<endl;
        for (int j = 0; j < edges[i].size(); ++j) {
            cout<<edges[i][j] <<" ";
        }
        cout<<endl;
    }   
}
