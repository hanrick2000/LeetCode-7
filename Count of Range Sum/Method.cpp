//Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
//Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
//
//Note:
//A naive algorithm of O(n2) is trivial. You MUST do better than that.
//
//Example:
//Given nums = [-2, 5, -1], lower = -2, upper = 2,
//Return 3.
//The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

//试想一个naive的做法，先求出前缀和，然后两重循环，对于  sums[i],寻找前面的j, 0...i-1,似的    lower <=sums[i] - sums[j] <= upper.  这样做要O(n^2).但如果我们把i之前出现过的sum全放进一个multiset ,  那么我们就可以在log n 的时间下求出    sums[i] - upper <=x <=sum[i] - lower 的个数，可以用c++的upperbound(sum[i] - lower) - lower_bound(sums[i] - upper) 这个差可以用distance函数求出来。
//注意，一开始set里面要有一个0. 这其实表示 sum[-1].  所有的从0开始到i的和  正通过sums[i] - sums[-1]求得，不能遗漏。
    

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        multiset<long long> myset;
        myset.insert(0);
        int res = 0;
        long long sum = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            
            sum += nums[i];
            res += distance(myset.lower_bound(sum-upper),  myset.upper_bound(sum - lower));
            myset.insert(sum);
        }
        return res;
        
    }
};

