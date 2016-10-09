class Solution {
public:
    void dfs(int left, int n, vector<string> &s, int right, string cur) {
        if(left == n) {
            if(right == n) {
                s.push_back(cur);
                return;
            }
            else {
                return dfs(left,n,s,right+1,cur+")");
            }
        }
        dfs(left+1,n,s,right,cur+"(");
        if(left > right)  return dfs(left,n,s,right+1,cur+")");
    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> rst;
        dfs(0,n,rst,0,"");
        return rst;
    }
};