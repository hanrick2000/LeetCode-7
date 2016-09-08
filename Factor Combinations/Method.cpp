//Numbers can be regarded as product of its factors. For example,
//
//8 = 2 x 2 x 2;
//  = 2 x 4.
//Write a function that takes an integer n and return all possible combinations of its factors.
//
//Note: 
//You may assume that n is always positive.
//Factors should be greater than 1 and less than n.
//Examples: 
//input: 1
//output: 
//[]
//input: 37
//output: 
//[]
//input: 12
//output:
//[
//  [2, 6],
//  [2, 2, 3],
//  [3, 4]
//]
//input: 32
//output:
//[
//  [2, 16],
//  [2, 2, 8],
//  [2, 2, 2, 4],
//  [2, 2, 2, 2, 2],
//  [2, 4, 4],
//  [4, 8]
//]

//显然大体上dfs+回溯不会错。有一点小细节需要处理，例如输入12，  第一次迭代时不允许出现[12],但是 如果24  迭代到第二次 12时  就允许返回12，所以我们还要在循环上加一个控制条件 。第一次进去i*i<= n ,  以后就没有这个限制条件

class Solution {
public:

    void dfs(int n, vector<int> &cur, vector<vector<int>> &res, int start,bool flag) {
        
        if(n==1&&!flag) {
            res.push_back(cur);
            return;
        }
        
        for(int i = start; i<=n; ++i) {
            if(flag&&i>n/i) break;
            
            if(n%i == 0) {
                cur.push_back(i);
                dfs(n/i, cur,res,i,false);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        
        vector<vector<int>> res;
        vector<int> cur;
        
        dfs(n,cur,res,2,true);
        return res;
        
    }
};