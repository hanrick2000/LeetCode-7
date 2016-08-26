//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
//Example 1:
//Input: [7, 1, 5, 3, 6, 4]
//Output: 5
//
//max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
//Example 2:
//Input: [7, 6, 4, 3, 1]
//Output: 0
//
//In this case, no transaction is done, i.e. max profit = 0.

//线性扫描一遍prices， 扫到i时，记录下当前price - i之前的最低price的差有没有大于最大利润，一遍扫描即可

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        
        int min_price  = prices[0],max_profit=0;
        
        for(int i = 1; i < prices.size(); ++i) {
            max_profit = max(prices[i]-min_price, max_profit);
            min_price = min(prices[i],min_price);
            
        }
        
        return max_profit;
    }
};