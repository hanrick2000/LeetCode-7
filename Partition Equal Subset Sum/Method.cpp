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

事实证明这个超时，并且如果我们用combination sum II 也会超时其实两者本质一样的，都是指数型。所以得用DP， 即背包问题。即只要把bound设为sum/2. 看看最大和是不是sum/2就行。但根据正统的方法来做需要O(kn)时间空间，所以空间超了。
    
    
            //if nums[i] > w: 
            //    dp[i+1][w] = dp[i][w];
            //else:
            //    dp[i+1][w] = max(dp[i][w-nums[i]] + nums[i], dp[i][w])
    
    bool subsetSum(int bound, vector<int> &nums)  {
        vector<vector<int>> dp(nums.size()+1, vector<int>(bound+1));
        for(int i = 1; i < dp.size(); ++i) {
            for(int j = 1; j < dp[0].size(); ++j) {
                if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else {
                    dp[i][j] = max(dp[i-1][j-nums[i-1]] + nums[i-1], dp[i-1][j]);
                }
            }
        }
        return dp.back().back() == bound;
    }
    
    

    bool canPartition(vector<int>& nums) {
        
        int target = 0;
        for(int num: nums) target += num;
        
        if(target&1) return false;
        
        target>>=1;
        
        return subsetSum(target, nums);
    }

然后我们发现，每一行dp[i][j]其实仅仅跟dp[i-1][j]有关。因此我们可以仅用O(n)空间。
    