//You are climbing a stair case. It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


// 第n步总数等于n-1步和n-2步的和，用求斐波那契数列的方法可得。O(n)时间 O(1)空间

class Solution {
public:
    int climbStairs(int n) {
        
        int p = 1, pre = 1;
        
        for(int i = 1; i < n; ++i) {
            pre += p;
            p = pre-p;
        }
        
        return pre;
        
    }
};