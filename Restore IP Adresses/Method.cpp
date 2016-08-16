//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//For example:
//Given "25525511135",
//
//return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
//
//Show Tags

//还是dfs, 关键还是要搞清楚遇到0该怎么办，是直接填0，继续深搜。


class Solution {
public:    
    void dfs(string &s, int p, int depth, vector<string> &res, string &curIP) {
        
        if(depth>4) {
            if(p == s.size()) {
                res.push_back(curIP);
            }
            return;
        }
        
        if(p >= s.size()) {
            return;
        }
        
        if(s[p] == '0') {
            
            curIP += curIP == ""?"0":".0";
            return dfs(s,p+1, depth+1,res,curIP);
        }
        
        int temp = 0;
        
        string tmp = curIP,tmp1;
        
        for(int i = p; i < s.size(); ++i) {
            
            temp = temp*10 + s[i]-'0';
            if(temp > 255) break;
            tmp1 += s[i];
            
            curIP += curIP == ""?tmp1 :"."+tmp1;
            dfs(s,i+1, depth+1,res,curIP);
            
            curIP = tmp;
        }
        
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string curIP;
        dfs(s,0, 1,res,curIP);
        return res;
        
    }
};