//Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
//
//Note:
//Given m satisfies the following constraint: 1 ≤ m ≤ length(nums) ≤ 14,000.
//
//Examples:
//
//Input:
//nums = [1,2,3,4,5]
//m = 2
//
//Output:
//9
//
//Explanation:
//There are four ways to split nums into two subarrays.
//The best way is to split it into [1,2,3] and [4,5],
//where the largest sum among the two subarrays is only 9.

//这道题的二分查找是对所有可能的解做二分搜索，验证它是不是可能的，排除所有不可能的解，最后二分循环出来的就是最优解。什么意思呢？因为数字非负，所以出来的解肯定是在数组的和与数组最大值之间。那么就在这里面进行二分查找。判断这个数字是不是可能，如何判断呢？  用贪心法，尽可能去让每一个subarray的和去靠这个值，如果超了就分配到下一组去，最后看看组数是否会超过m.超过了就将二分的下界严格往上，否则将二分上界设为当前的中点，由于这个值是一定在这个区间里的，所以二分出来后的p就是结果

class Solution {
public:

    int valid(vector<int>& nums, int m, int target) {
        
        int tmp  = 0;
        int count = 1;
        
        for(auto x: nums) {
            tmp += x;
            
            if(tmp > target) {
                
                tmp = x;
                
                ++count;
                
                if(count > m) return false;
           
            }
        }
        
        return true;
    }

    int splitArray(vector<int>& nums, int m) {

        int q = 0, p = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            q += nums[i];
            p = max(p,nums[i]);
        }
        
        while(p < q) {
            
            int c = (q-p)/2+p;
            
            if(valid(nums,m,c)) {
                q = c;
            }
 
            else {
                p = c+1;
            }
        }

        return p;
        
    }
};
