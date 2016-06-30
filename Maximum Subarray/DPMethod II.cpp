//解法二，可以先累加nums,让nums[i] 等于 nums[0]到nums[i]的和。 然后做一遍线性扫描，当扫描到i时，我们只需找出nums[0]到nums[i-1]中的最小值，然后num[i] - min 就是 以nums为结尾的最大值. 两种方法本质是一样的都是线性扫到i时 就能算出 以i为结尾的最大值。  都能做到时间复杂度O(n),空间复杂度O(1).


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        for(int i = 1; i<nums.size(); ++i) {
            nums[i]+=nums[i-1];
        }
        
        int mini = 0, maxi = INT_MIN;
        for(int i = 0; i <nums.size(); ++i) {
            maxi = max(maxi, nums[i]-mini);
            mini = min(mini, nums[i]);
        }
        
        return maxi;
        
    }
};

// 放进一个循环。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int mini = min(0,nums[0]), maxi = nums[0];
        
        for(int i = 1; i<nums.size(); ++i) {
            nums[i]+=nums[i-1];
            maxi = max(maxi, nums[i]-mini);
            mini = min(mini, nums[i]);
        }
        
        return maxi;
        
    }
};