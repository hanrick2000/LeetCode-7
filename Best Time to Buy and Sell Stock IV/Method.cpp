//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
//Note:
//You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


//动态转移方程为

// local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i][j-1] + diff);    第j天  最多i次交易 且最后一次卖股票在第i天。

// global[i][j] = max(local[i][j], global[i][j-1]);，  前j天，最多i次交易的最大利润
//diff 为第i天与第i-1天的股价差



class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        if(k >= prices.size()) {
            
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


        vector<vector<int>> local(k+1, vector<int> (prices.size()));
        vector<vector<int>> global(k+1, vector<int> (prices.size()));
        
        for(int i = 1; i < local.size(); ++i) {
            for(int j = 1; j < local[0].size(); ++j) {
                int diff = prices[j] - prices[j-1];
                local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i][j-1] + diff); 
                global[i][j] = max(local[i][j], global[i][j-1]);
            }
        }
        
        return global.back().back();
        
    }
};