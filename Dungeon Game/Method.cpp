//The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
//
//The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
//
//Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
//
//In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
//
//
//Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
//
//For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
//
//-2 (K)	-3	3
//-5	-10	1
//10	30	-5 (P)
//
//Notes:
//
//The knight's health has no upper bound.
//Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

//这道题得倒着做，设dp[i][j]为从i,j到达右下角所需要的最少HP， 那么我们有以下状态方程： dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j+1]) - dungeon[i][j]);  初始化右下角，填写最下边和最右边，然后循环。

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        if(!dungeon.size() || !dungeon[0].size()) return 1;

        vector<vector<int>> dp(dungeon.size(), vector<int> (dungeon[0].size()));
        
        if(dungeon.back().back() >=0 ) dp.back().back() = 1;
        else dp.back().back() = 1 - dungeon.back().back();
        
        
        for(int i = dp[0].size()-2; i >= 0; --i) dp.back()[i] = max(1, dp.back()[i+1] - dungeon.back()[i]);
        
        for(int i = dp.size()-2; i >= 0; --i)  dp[i].back() = max(1,dp[i+1].back() - dungeon[i].back());

        for(int i = dp.size()-2; i >= 0; --i) {
            for(int j = dp[0].size()-2; j >= 0; --j)  dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j+1]) - dungeon[i][j]);
        }

        return  dp[0][0];
        
    }
};