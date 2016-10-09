//Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//Note:
//Both the array size and each of the array element will not exceed 100.
//
//Example 1:
//
//Input: [1, 5, 11, 5]
//
//Output: true
//
//Explanation: The array can be partitioned as [1, 5, 5] and [11].
//Example 2:
//
//Input: [1, 2, 3, 5]
//
//Output: false
//
//Explanation: The array cannot be partitioned into equal sum subsets.

如果可以用dfs不超时的话就很简单的。先算出和总共是多少，和是奇数returnfalse。  然后dfs target一半的和就可以了。最坏O（2^n）。

class Solution {
public:

    bool canPartitionHelper(vector<int>& nums, int depth, int left) {
        if(nums.size() == depth)  {
            return left == 0;
        }
        
        if(left < 0) return false;
        if(left == 0) return true;
        
        return  canPartitionHelper (nums, depth+1, left - nums[depth]) || canPartitionHelper (nums, depth+1, left);
        
    }

    bool canPartition(vector<int>& nums) {
        long long target = 0;
        for(auto num: nums) target += num;
        
        if(target%2) return false;
        
        target >>=1;
        
        return canPartitionHelper (nums, 0, target);
    }
};