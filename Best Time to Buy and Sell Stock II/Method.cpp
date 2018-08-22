//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

//贪心法，只要第二天股价降了，当天如果持股就把股票买了，只要第二天股价升了，当天如果没持股，就把股票买入。要注意最后一天，可能要卖股票。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        prices.push_back(INT_MIN);
        bool hasStock = false;
        int profit = 0;
        
        for(int i = 0; i < prices.size()-1; ++i) {
            if(prices[i] < prices[i+1]&&!hasStock) {
                hasStock = true;
                profit-= prices[i];
            }
            
            if(prices[i] > prices[i+1] && hasStock) {
                hasStock = false;
                profit+= prices[i];
            }
            
        }
        
        return profit;
    }
    
    其实就是这么做
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
        }

        return profit;
    }
};