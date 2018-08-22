//Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
//For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

//很简单的DP, 依次减去小的square

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp = {0,1};

        for(int i = 2; i <= n; ++i) {
            
            int mini = i;
            
            for(int j = 2; j*j<=i ; ++j) {
                mini = min(mini, dp[i-j*j]+1);
            }
            
            dp.push_back(mini);
        }
        
        return dp.back();
    }
};

用一个BFS搜索更快
    
class Solution {
public:
    int numSquares(int n) {
        
        vector<int> square;
        bool visited[n] = {false};    //注意这个visited 数组的使用是精华
        for(int i = 1; i * i <= n; ++i) {
            square.push_back(i*i);
        }
        if(square.back() == n) return 1;
        
        queue<int> myque;
        myque.push(n);
        
        int level = 0;
        while(myque.size()) {
            int len = myque.size();
            for(int i = 0; i < len; ++i) {
                int tmp = myque.front();
                myque.pop();
                if(tmp == 0) return level;
                for(int i = square.size() - 1; i >= 0; --i) {
                    if(square[i] == tmp) return ++level;
                    if(square[i] > tmp) continue;
                    if(visited[tmp - square[i]]) continue;
                    
                    myque.push(tmp - square[i]);
                    visited[tmp - square[i]] = true;
                }
            }
            ++level;
        }
            
        return level;
    }
};
