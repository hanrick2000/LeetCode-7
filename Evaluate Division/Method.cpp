//Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
//
//Example:
//Given a / b = 2.0, b / c = 3.0. 
//queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
//return [6.0, 0.5, -1.0, 1.0, -1.0 ].
//
//The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.
//
//According to the example above:
//
//equations = [ ["a", "b"], ["b", "c"] ],
//values = [2.0, 3.0],
//queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
//The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.


//这题很简单，dfs输出结果就可以，注意visited过的 不要忘记continue，剪枝。

class Solution {
public:
    
    bool query(string a, string b, unordered_map<string,unordered_map<string,double>> &edges, unordered_set<string> &visited, double &res) {
        
        if(edges.find(a) == edges.end() || edges.find(b) == edges.end()) {
            return false;
        }
        
        if(a == b) {
            res = 1;
            return true;
        }
        
        visited.insert(a);
        
        for (auto it = edges[a].begin(); it!=edges[a].end();++it) {
            
            if(visited.find(it->first)!=visited.end()) continue;
            if(query(it->first,b,edges,visited, res)) {
                visited.erase(a);
                res*= edges[a][it->first];
                return true;
            } 
        }
        
        visited.erase(a);
        
        return false;
               
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
               
        vector<double> rst;
        unordered_map<string,unordered_map<string,double>> edges;
               
        for(int i = 0; i < equations.size(); ++i) {
            edges[equations[i].first][equations[i].second] = values[i];
                   
            if(values[i]!=0.0) edges[equations[i].second][equations[i].first] = 1.0/values[i];
        }
               
        unordered_set<string> visited;
               
        for(int i = 0; i < queries.size(); ++i) {
                   
            double res = 1;
                   
            if(query(queries[i].first, queries[i].second, edges, visited, res)) {
                rst.push_back(res);
            }
            else {
                rst.push_back(-1.0);
            }
        }
               
        return rst;
    }
};