//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
//
//There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
//
//For example:
//
//2, [[1,0]]
//There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
//
//4, [[1,0],[2,0],[3,1],[3,2]]
//There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
//
//Note:
//The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

//和I没啥区别，在myque循环里面每一次找到一个没有入度的点，就可以加入队列。

class Node {
public:
    int indegree;
    vector<int> edges;
    Node():indegree(0){};
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        Node vertex[numCourses];
        
        vector<int> res;
        
        for(int i = 0; i < prerequisites.size(); ++i) {
            
            if(prerequisites[i].second == prerequisites[i].first) return {};   // 自环
            vertex[prerequisites[i].second].edges.push_back(prerequisites[i].first);
            ++vertex[prerequisites[i].first].indegree;
        }
        
        queue<int> myque;
        
        for(int i = 0; i < numCourses; ++i) {
            if(!vertex[i].indegree) myque.push(i);
        }
        
        while(myque.size()) {
            int tmp = myque.front();
            myque.pop();
            res.push_back(tmp);
            
            for(int i = 0; i < vertex[tmp].edges.size(); ++i) {
                if(!--vertex[vertex[tmp].edges[i]].indegree) myque.push(vertex[tmp].edges[i]);
            }
        }
        
        
        for(int i = 0; i < numCourses; ++i) {
            if(vertex[i].indegree) return {};
        }
        
        return res;
    }
};