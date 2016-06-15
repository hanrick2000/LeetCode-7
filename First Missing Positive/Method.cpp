//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//Given [1,2,0] return 3,
//and [3,4,-1,1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space.


class Solution {
public:

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int firstMissingPositive(vector<int>& nums) {
        
        nums.push_back(-1);
        for(int i = 0; i < nums.size(); ++i) {
            
            while(nums[i]&&nums[i]<nums.size()&&i!=nums[i]&&nums[i]!=nums[nums[i]]) {
                swap(nums[i],nums[nums[i]]);
            }
        }
        
        int i = 1;
        for(; i < nums.size(); ++i) {
            if(i != nums[i]) break;
        }
        
        return i;
    }
};