//Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.
//
//Rules for a valid pattern:
//Each pattern must connect at least m keys and at most n keys.
//All the keys must be distinct.
//If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
//The order of keys used matters.
//
//Explanation:
//| 1 | 2 | 3 |
//| 4 | 5 | 6 |
//| 7 | 8 | 9 |
//Invalid move: 4 - 1 - 3 - 6 
//Line 1 - 3 passes through key 2 which had not been selected in the pattern.
//
//Invalid move: 4 - 1 - 9 - 2
//Line 1 - 9 passes through key 5 which had not been selected in the pattern.
//
//Valid move: 2 - 4 - 1 - 3 - 6
//Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern
//
//Valid move: 6 - 5 - 4 - 1 - 9 - 2
//Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.
//
//Example:
//Given m = 1, n = 1, return 9.

这个几乎是纯dfs+回溯写的。。没有任何DP。

class Solution {
public:

    void dfs(int left, int start, vector<bool> &visited, int &res) {
        
        if(visited[start]) return;
        
        if(!left) {
            ++res;
            return;
        }
        
        visited[start] = true;
        
        for(int i = 1; i <= 9; ++i ) {
            if(abs(start - i) == 6) {
                if(!visited[(i+start)/2]) continue;
            }
            
            if(start%3==1&&i == start+2 || i%3 == 1&&start == i+2) {
                if(!visited[(i+start)/2]) continue;
            }
            
            if(abs(start - i) == 8) {
                if(!visited[(i+start)/2]) continue;
            }
            if(start == 7 && i == 3 || i == 7 && start == 3) {
                if(!visited[(i+start)/2]) continue;
            }
            
            dfs(left-1, i, visited, res);
        }
        
        visited[start] = false;  //千万不要忘了这句回溯。。。
        
        return;
    }

    int numberOfPatterns(int m, int n) {
        
        int rst = 0;
        
        for(int i = m; i <= n; ++i) {

            vector<bool> visited(9,false);
            int res1 = 0, res2 = 0, res3 = 0;
            
            dfs(i-1, 1, visited, res1);
            
            visited = vector<bool> (9,false);
            dfs(i-1, 2, visited, res2);
            
            visited = vector<bool> (9,false);
            dfs(i-1, 5, visited, res3);
            
            rst += 4*res1 + 4*res2 + res3;
        }
        
        return rst;
        
    }
};