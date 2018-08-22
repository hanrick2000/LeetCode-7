//Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

//很简单，不要想复杂了。只要每一次记录该数出现的位置，然后下次遇到这个数，看看两个索引是否差值小于k。

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        for(int i = 0; i < nums.size(); ++i) {
            if(mymap.count(nums[i]) && i - mymap[nums[i]] <= k) return true;
            mymap[nums[i]] = i;
        }
        return false;
    }
};