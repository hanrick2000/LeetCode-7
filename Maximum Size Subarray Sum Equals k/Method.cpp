//Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.
//
//Example 1:
//Given nums = [1, -1, 5, -2, 3], k = 3,
//return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)
//
//Example 2:
//Given nums = [-2, -1, 2, 1], k = 1,
//return 2. (because the subarray [-1, 2] sums to 1 and is the longest)
//
//Follow Up:
//Can you do it in O(n) time?

//看到subarray和就想到把原数组变成前缀和，然后可以用一个hashmap存储（前缀和，下标）对，每一次求得一个新前缀和，就看看该和-k是否出现在hashmap中。 如果前缀和出现过，我们就忽略，因为要求的是最长，相同的和肯定保存index小的比较好。

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        unordered_map<int,int> mymap;

        mymap[0] = -1;
        
        int res = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(i) nums[i] += nums[i-1];
            
            if(mymap.find(nums[i]-k)!=mymap.end()) res = max(res, i - mymap[nums[i]-k]);
            
            if(mymap.find(nums[i])==mymap.end()) mymap[nums[i]] = i;
        }
        
        return res;
        
    }
};