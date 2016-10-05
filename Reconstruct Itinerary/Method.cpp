//Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
//
//Note:
//If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
//All airports are represented by three capital letters (IATA code).
//You may assume all tickets form at least one valid itinerary.
//Example 1:
//tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
//Example 2:
//tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
//Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
//Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.

//这题只会用DFS暴力搜索，每次搜索往字母排序最靠前的搜索，递归的终点是当前路径长度等于n,一旦成功就停止搜索，因为这肯定是排序最靠前的结果。
//    这里有很多细节要注意，萎了让字母排序，所以边要用set来存，同时这个图会有环，我们必须在dfs里记录哪些边访问过。同时因为一条边可能会出现好几次，即买了好几场同样的机票，记录机票出现过得用计数的方式，不能用bool的方式。这题建议用递归的dfs,不建议用迭代，第一方面你要回溯。第二方面你要记录哪一张机票访问过时是通过访问机票的目的地点来确认，不是通过扔进栈里来确认。

class Solution {
public:

    bool dfs(vector<string> &cur,  unordered_map<string, set<string>> &edges, unordered_map<string, int> &visited, string c, int n) {
    
        if(cur.size() == n) {
            return true;
        }
        
        for(auto it = edges[c].begin(); it != edges[c].end(); ++it) {
            
            if(!visited[c + *it]) continue;
            
            cur.push_back(*it);
            
            visited[c + *it]--;
            if(dfs(cur, edges,visited, *it, n)) return true;
            
            visited[c + *it]++;
            
            cur.pop_back();
        }
        
        return false;
    }
    
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
        
        unordered_map<string, set<string>> edges;
        unordered_map<string, int> visited;
        
        for(int i = 0; i < tickets.size(); ++i) {
            
            edges[tickets[i].first].insert(tickets[i].second);
            visited[tickets[i].first + tickets[i].second]++;
        }
        
        vector<string> res;
        res.push_back("JFK");
        
        dfs(res, edges,visited, "JFK", tickets.size()+1);
        return res;
    }
};