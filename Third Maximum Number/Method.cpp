//Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
//
//Example 1:
//Input: [3, 2, 1]
//
//Output: 1
//
//Explanation: The third maximum is 1.
//Example 2:
//Input: [1, 2]
//
//Output: 2
//
//Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
//Example 3:
//Input: [2, 2, 3, 1]
//
//Output: 1
//
//Explanation: Note that the third maximum here means the third maximum distinct number.
//Both numbers with value 2 are both considered as second maximum.

这题要注意 max1,max2,max3不能相等的（不能并列），所以在循环时一定要把 nums[i] == max1 || nums[i] == max2 || nums[i] == max3这种情况给排除。

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LONG_LONG_MIN, max2 = LONG_LONG_MIN, max3 = LONG_LONG_MIN;
        
        for(auto &x: nums) {
            if(x == max1 || x == max2 || x == max3) continue;
            if(x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max3 = max2;
                max2 = x;
            } else if (x > max3) {
                max3 = x;
            }
        }
        return max3 == LONG_LONG_MIN? max1: max3;
    }
};