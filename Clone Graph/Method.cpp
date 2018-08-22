//Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
//
//
//OJ's undirected graph serialization:
//Nodes are labeled uniquely.
//
//We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
//As an example, consider the serialized graph {0,1,2#1,2#2,2}.
//
//The graph has a total of three nodes, and therefore contains three parts as separated by #.
//
//First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//Second node is labeled as 1. Connect node 1 to node 2.
//Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
//Visually, the graph looks like the following:
//
//       1
//      / \
//     /   \
//    0 --- 2
//         / \
//         \_/

//这道题bfs，有很多注意点，1）如何防治环带来的死循环？ 这个要控制队列的入队控制。2）要克隆的点不能重复实例化，所以要根据label，记录指针节点，以便下次bfs检索回这个节点.


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        if(!node) return NULL;
        queue<UndirectedGraphNode*> que;
        
        que.push(node);
        
        unordered_map<int,UndirectedGraphNode*> mymap;
        
        
        while(que.size()) {
            UndirectedGraphNode* tmp = que.front();
            que.pop();
            UndirectedGraphNode* root;
            if(mymap.find(tmp->label)!=mymap.end()) {
                root = mymap[tmp->label];
            }
            else {
                root = new UndirectedGraphNode(tmp->label);
                mymap[tmp->label] = root;
            }
    
            for(auto &x: tmp->neighbors) {
                if(mymap.find(x->label)!=mymap.end()) {
                    root->neighbors.push_back(mymap[x->label]);
                }
                else {
                    UndirectedGraphNode* neib = new UndirectedGraphNode(x->label);
                    mymap[x->label] = neib;
                    root->neighbors.push_back(neib);
                    que.push(x);
                }
            }
        }
        
        return mymap[node->label];
        
    }
    
    可以用  dfs ,几乎就是把循环里的内容拷贝出来。
        
    void dfs(UndirectedGraphNode *node, Mymap &mymap) {

        for(auto &neighbor: node->neighbors) {
            if(mymap.count(neighbor)) {
                mymap[node]->neighbors.push_back(mymap[neighbor]);
            } else {
                mymap[neighbor] = new UndirectedGraphNode(neighbor->label);
                mymap[node]->neighbors.push_back(mymap[neighbor]);
                dfs(neighbor,mymap);
            }
        }
    }


    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        if(!node) return NULL;
        
        Mymap mymap;
        
        UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
        
        mymap[node] = newnode;

        dfs(node, mymap);
        
        return newnode;
    }
};