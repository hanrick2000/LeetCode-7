//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
//For example:
//
//2, [[1,0]]
//There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
//
//2, [[1,0],[0,1]]
//There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

//这题说了是拓补排序。用邻接表效率比较高。由于节点是0到n-1的数字，所以可以把节点放进一个数组，每一个节点记录临街节点和入度数。然后dfs,先把所有入度为0的进队列，每一次访问一个节点，将所有的邻接节点的入度数--。如果到0就放进队列。

class Node {
public:
    int indegree;
    vector<int> edges;
    Node():indegree(0){};
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<Node> vertex(numCourses);
        
        for(int i = 0; i < prerequisites.size(); ++i) {
            
            if(prerequisites[i].second == prerequisites[i].first) return false;   // 自环
            vertex[prerequisites[i].second].edges.push_back(prerequisites[i].first);
            ++vertex[prerequisites[i].first].indegree;
        }
        
        queue<int> myque;
        
        for(int i = 0; i < vertex.size(); ++i) {
            if(!vertex[i].indegree) myque.push(i);
        }
        
        while(myque.size()) {
            int tmp = myque.front();
            myque.pop();
            
            for(int i = 0; i < vertex[tmp].edges.size(); ++i) {
                if(!--vertex[vertex[tmp].edges[i]].indegree) myque.push(vertex[tmp].edges[i]);
            }
        }
        
        
        for(int i = 0; i < vertex.size(); ++i) {
            if(vertex[i].indegree) return false;
        }
        
        return true;
        
    }
};