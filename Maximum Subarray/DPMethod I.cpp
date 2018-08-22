////Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
//the contiguous subarray [4,−1,2,1] has the largest sum = 6.
//
//click to show more practice.
//
//More practice:
//If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

// 动态规划  典型解法一： 由于至少有一个解，我们可以求一个opt数组，opt[i]表示以nums[i]为结尾的最大subarray. 易知，opt[i] = max(nums[i], opt[i-1] + nums[i]) 求出每一个 opt[i]后，再做一遍线性扫描就可以求出最大值。 时间空间都是O(n)，当然我们可以覆盖掉nums，这样空间也是O(1).
//而事实上，我们可以在求解opt[i]的那个扫描中求最大值，然后我们发现，这样就不用存在整个数组，因为每一次求opt[i]时仅用到了opt[i-1],因此我们可以就用一个变量tmp来保存之前的opt。然后不断求解新opt时，更新max. 这样只要一遍扫描和O(1)空间即可。

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if(!nums.size()) return 0;
        int opt = nums[0], maxi= opt,tmp;

        for(int i = 1; i < nums.size(); ++i) {
            tmp = opt;
            opt = max(nums[i], opt+nums[i]);
            maxi = max(maxi,opt);
        }
        
        return maxi;
    }
    
        if(!nums.size()) return 0;
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] = max(nums[i], nums[i] + nums[i-1]);
            res = max(res, nums[i]);
        }
        return res;
};