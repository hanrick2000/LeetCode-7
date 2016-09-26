//Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
//
//If there are multiple solutions, return any subset is fine.
//
//Example 1:
//
//nums: [1,2,3]
//
//Result: [1,2] (of course, [1,3] will also be ok)
//Example 2:
//
//nums: [1,2,4,8]
//
//Result: [1,2,4,8]

//这题动态规划，先排序。  然后构建一个dp数组，记录当前数最大的subset子集。
//然后计算dp[i]可以通过dp[0]...dp[i-1]构建。再建立一个dp2来记录上一个数

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> dp(nums.size(),1);
        vector<int> dp2(nums.size(),-1);
        
        for(int i = 1; i < dp.size(); ++i) {
            int max = 0, maxIndex = -1;
            for(int j = i-1; j >= 0; --j) {
                if((nums[i]%nums[j]) == 0) {
                    if(dp[j] > max) {
                        maxIndex = j;
                        max = dp[j];
                    }
                }
            }

            dp[i] = max+1;
            dp2[i] = maxIndex;
        }
        
        vector<int> rst;
        
        int max = INT_MIN, maxIndex = -1;
        
        for(int i = 0; i < dp.size(); ++i) {
            if(dp[i] > max) {
                max = dp[i];
                maxIndex = i;
            }
        }

        while(maxIndex!=-1) {
            rst.push_back(nums[maxIndex]);
            maxIndex = dp2[maxIndex];
        }
        
        return rst;
    }
};