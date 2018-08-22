//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete at most two transactions.


//You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


//这题可以用两个数组，A记录第i天前 1次trans最大的利润，  B记录第i天到最后 1次trans最大利润，然后再对每天求A[i] + B[i+1]的最大值。

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        if(!prices.size()) return 0;
        
        int res = 0;
        
        vector<int> l(prices.size()), r(prices.size());
        
        int lmin= prices[0]; 
        
        for(int i = 1; i < l.size(); ++i) {
            
            l[i] = max(l[i-1], prices[i] - lmin);
            
            lmin = min(prices[i], lmin);
        }
        
        int rmax  = prices.back();
        
        for(int i = r.size() - 2; i >= 0; --i) {
            
            r[i] = max(r[i+1], rmax - prices[i]);
            
            rmax = max(prices[i], rmax);
        }        
        
        for(int i = 0; i < r.size()-1; ++i) {
            
            res = max(res, l[i] + r[i+1]);
        }
        
        res = max(res, l.back());

        return res;
    }
    
    网上最快的方法。
    
    int maxProfit(vector<int>& prices) {
        
        int buy_one(INT_MIN), sell_one(0), buy_two(INT_MIN), sell_two(0);
            
        for(int &price: prices) {
            buy_one = max(buy_one, -price);
            sell_one = max(sell_one, price + buy_one);
            buy_two = max(buy_two, -price + sell_one);
            sell_two = max(sell_two, price + buy_two);
        }
        return sell_two;
    }
};