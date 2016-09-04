//Note: This is an extension of House Robber.
//
//After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
//
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

//这题就考虑 最后一站你抢还是不抢，不抢，最大利益就相当于做一遍 I,只不过范围从0到n-1. 抢相当于做一遍1到n. 注意当输入只有一个house的特殊情形。

class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size()) return 0;
        if(nums.size()==1) return nums[0];
        
        int p2 = 0, p1 = 0, max1 = INT_MIN, max2 = max1;
        
        for(int i = 0; i < int(nums.size())-1; ++i) {
            int tmp = max(nums[i] + p2, p1);
            p2 = p1;
            p1 = tmp;
            max1 = max(max1,tmp);
        }
        
        p2 = 0, p1 = 0;
        
        for(int i = 1; i < nums.size(); ++i) {
            int tmp = max(nums[i] + p2, p1);
            p2 = p1;
            p1 = tmp;
            max2 = max(max2,tmp);
        }
        
        return max(max1,max2);
    }
};