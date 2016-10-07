//A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
//
//Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.
//
//If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.
//
//Note:
//
//The number of stones is ≥ 2 and is < 1,100.
//Each stone's position will be a non-negative integer < 231.
//The first stone's position is always 0.
//Example 1:
//
//[0,1,3,5,6,8,12,17]
//
//There are a total of 8 stones.
//The first stone at the 0th unit, second stone at the 1st unit,
//third stone at the 3rd unit, and so on...
//The last stone at the 17th unit.
//
//Return true. The frog can jump to the last stone by jumping 
//1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
//2 units to the 4th stone, then 3 units to the 6th stone, 
//4 units to the 7th stone, and 5 units to the 8th stone.
//Example 2:
//
//[0,1,2,3,4,8,9,11]
//
//Return false. There is no way to jump to the last stone as 
//the gap between the 5th and 6th stone is too large.

//这题DP肯定要O^2，用一个数组dp记录  跳到石头i上最后一条跳了几步，然后求dp[i+1]可以用dp[0]...dp[i]来确定，为了不超时，记录一个当前最大步长，对于超过这个步长之外的石头直接不予考虑。

class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        vector<unordered_set<int>> dp(stones.size());
        dp[0].insert(0);
        
        int maxj = 0;
        for(int i = 1; i < stones.size(); ++i) {
            for(int j = i-1; j >= 0; --j) {
                int t = stones[i]-stones[j];
                if(t > maxj + 1) break;
                
                if(dp[j].find(t) != dp[j].end() || dp[j].find(t +1) != dp[j].end() || dp[j].find(t-1) != dp[j].end()) {
                    dp[i].insert(t);
                    maxj = max(maxj, t);
                }
            }
        }
        
        return dp[stones.size()-1].size();
    }
};