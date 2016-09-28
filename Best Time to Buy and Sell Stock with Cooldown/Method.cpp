//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
//
//You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//Example:
//
//prices = [1, 2, 3, 0, 2]
//maxProfit = 3
//transactions = [buy, sell, cooldown, buy, sell]

//这题每一天总共4种可能：
//1) 有股   卖
//2）有股 不卖
//3）没股 买
//4）没股 不买
//然后写状态转移方程即可
//记得第0天前两种情况是不可能的，可以把它的最大收益调成-无穷

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(!prices.size())  return 0;

        vector<int> dp(4);
        dp[0] = INT_MIN;
        dp[1] = INT_MIN;
        dp[2] = - prices[0];
        
        for(int i = 1; i < prices.size(); ++i) {
            
            vector<int> dp2(4);
            
            dp2[0] = max(dp[1] + prices[i], dp[2] + prices[i]);
            
            dp2[1] = max(dp[1], dp[2]);
            
            dp2[2] = dp[3] - prices[i];
            
            dp2[3] = max(dp[0], dp[3]);
            
            dp = dp2;
        }
        
        int rst = INT_MIN;
        
        for(auto x: dp) {
            rst = max(x, rst);
        }
        
        return rst;
        
    }
};