//You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//
//Example 1:
//coins = [1, 2, 5], amount = 11
//return 3 (11 = 5 + 5 + 1)
//
//Example 2:
//coins = [2], amount = 3
//return -1.
//
//Note:
//You may assume that you have an infinite number of each kind of coin.  

很显然用dp, 空间O(amount), 时间O(amount * coins).

int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        
        for(int i = 1; i <= amount; ++i) {
            for(int j = 0; j < coins.size() && coins[j] <= i; ++j) {
                if(dp[i - coins[j]]!=-1) dp[i] = dp[i] == -1? dp[i - coins[j]]+1: min(dp[i], dp[i - coins[j]]+1);
            }
        }
        
        return dp.back();
        
    }

用bfs, 空间  O(m).时间O(amount)(试想一下  最多只要把amount个点访问后就好)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        queue<int> myque;
        //vector<bool> visited(amount+1, false);
        bool visited[amount+1] = {false};
        myque.push(amount);
        visited[amount] = true;
        
        int level = 0;
        
        while(myque.size()) {
            int len = myque.size();
            for(int i = 0; i < len; ++i)  {
                int tmp = myque.front();
                myque.pop();
                for(int j = coins.size()-1; j >= 0; --j) {
                    if(tmp - coins[j] == 0) return ++level;
                    if(tmp - coins[j] < 0) continue;
                    if(visited[tmp - coins[j]]) continue;
                    myque.push(tmp - coins[j]);
                    visited[tmp - coins[j]] = true;
                }
            }
            ++level;
        }
        return -1;
    }
};