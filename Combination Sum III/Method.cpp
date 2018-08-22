//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//
//Example 1:
//
//Input: k = 3, n = 7
//
//Output:
//
//[[1,2,4]]
//
//Example 2:
//
//Input: k = 3, n = 9
//
//Output:
//
//[[1,2,6], [1,3,5], [2,3,4]]

这题还是标准的dfs和回溯, 不过要保证你怎么pruning，。  还是通过下一层dfs返回向上一层时提供一个bool信号， 盖层dfs返回如果超过了n表示下一层也可以停止了，返回false。否则返回true, 表示上一层得继续进行下一个dfs。

class Solution {
public:

    bool dfs(int k, vector<vector<int>> &res, vector<int> &cur, int n, int start) {
        if(!k) {
            if(n) return true;
            if(!n) {
                res.push_back(cur);
            
            }
            return false;
        }
        
        for(int i = start; i <= 9; ++i) {
            cur.push_back(i);
            if(!dfs(k-1,res,cur,n-i,i+1)) {
                cur.pop_back();
                return true;
            }
            
            cur.pop_back();
            
        }
        
        return true;

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        
        dfs(k,res,cur,n,1);
        return res;
    }
    
    还是这么做吧。。
    
    void dfs(int depth, vector<int> &cur, vector<vector<int>> &res, int target, int k) {
        if(k == 0) {
            if(target == 0) res.push_back(cur);
            return;
        }

        for(int i = depth; i <= 9; ++i) {
            if(i > target) break;
            cur.push_back(i);
            dfs(i+1, cur, res, target - i, k-1);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        vector<vector<int>> res;
        
        dfs(1, cur, res, n, k);
        return res;
    }
};