//Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.
//
// Notice
//
//There is at least one subarray that it's sum equals to zero.

这个题和leetcode 325. Maximum Size Subarray Sum Equals k 很像，用hash表记录前缀和的下标。

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        vector<int> res;
        unordered_map<int,int> indexMap;
        indexMap[0] = -1;
        for(int i = 0; i < nums.size(); ++i) {
            if(i) nums[i] += nums[i-1];
            if(indexMap.count(nums[i])) {
                res.push_back(indexMap[nums[i]]+1);
                res.push_back(i);
                break;
            }
            indexMap[nums[i]] = i;
        }
        
        return res;
    }
};