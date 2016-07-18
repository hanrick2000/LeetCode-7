//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//For example,
//If n = 4 and k = 2, a solution is:
//
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//]

显然dfs， k是层数，基本思路是第一个数从1,2,...n挑， 第二个数从第一个数后一个开始挑，，直到层数到达k。我们怎么知道上一次跳完后的下一个数呢？  正好cur的最后一个元素纪录了上次挑的数，所以我们很快可以知道下一个数，所以下次循环i从这个数开始。还有一个优化  第1个数从1，2，3不是挑到n,其实是到在n-k+1。所以循环里面可以改变截止条件。

class Solution {
public:

    void combineHelper(vector<vector<int>>& res, vector<int> &cur, int k, int n) {
        if(!k) {
            res.push_back(cur);
            return;
        }

        for(int i = cur.size()?cur.back()+1:1; i <= n-k+1; ++i) {
            
            cur.push_back(i);
            combineHelper(res, cur, k-1, n);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> cur;
        
        combineHelper(res, cur, k, n);
        
        return res;
    }
};