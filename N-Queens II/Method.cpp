Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
    

//很简单，和i 一样,也可以不用ocupiedhash表，因为每次检查都要扫描一遍之前的，加一条判断列是否重复即可。
    
class Solution {
public:
    bool valid(vector<int> &cur, int depth, int i) {
        for(int j = 0; j < depth; ++j) {

            if(i == cur[j]||depth-j == abs(i-cur[j])) return false;
        }
        return true;
        
    }
    
    
    void dfs(int depth, vector<int> &cur, int &res, int n) {
        if(depth == n) {
            
            ++res;
            return;
        }
        
        for(int i = 0; i < n; ++i) {
            if(valid(cur, depth, i)) {
                cur[depth] = i;
                dfs(depth+1,cur,res,n);
            }

        }
    }
    

    int totalNQueens(int n) {
        vector<int> cur(n);
        int res = 0;

        dfs(0,cur,res,n);

        return res; 
    }
};