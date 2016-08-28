//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//For example, given s = "aab",
//Return
//
//[
//  ["aa","b"],
//  ["a","a","b"]
//]

//该题先快速得到二维矩阵map,  map[i][j] 表示 map[i...j]是回文，然后如果 map[i][j] == 1, map[i-1][j+1]可以通过s[i-1]与s[i+1]去表示。o(n^2)时间后，再用dfs搜索，map, 从depth开始，往map[depth][depth]后开始搜索，一遇到true，就将substring 放入，直到递归出口 将其放入结果。

class Solution {
public:
    void dfs(string &s, vector<vector<string>>& res,vector<string> &cur, int start, vector<vector<bool>> &mymap) {
        
        if(start>=s.size()) {
            res.push_back(cur);
            return;
        }
        
        for(int i = start; i < s.size(); ++i) {
            
            if(mymap[start][i]) {
                cur.push_back(s.substr(start,i-start+1));
        
                dfs(s,res,cur,i+1, mymap);
                cur.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        
        vector<vector<bool>> mymap(s.size(),vector<bool>(s.size()));

        vector<string> cur;
        vector<vector<string>> res;
        
        for(int i = 0; i < s.size(); ++i) {
            mymap[i][i] = true;
        }
        
        for(int i = 0; i < int(s.size())-1; ++i) {
            if(s[i]==s[i+1]) {
                mymap[i][i+1] = true;
            }
        }
        
        for(int i = 1; i < int(s.size())-1; ++i) {
            for(int k = 0; i+k+1 < s.size(); ++k) {
                if(!mymap[1+k][i+k]) continue;
                mymap[k][i+k+1] = s[k]==s[i+k+1];
            }
        }
        
        dfs(s,res,cur,0, mymap);
        
        return res;
        
    }
};
