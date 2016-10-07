//Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.
//
//Example 1:
//nums = [1, 3], n = 6
//Return 1.
//
//Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
//Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
//Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
//So we only need 1 patch.
//
//Example 2:
//nums = [1, 5, 10], n = 20
//Return 2.
//The two patches can be [2, 4].
//
//Example 3:
//nums = [1, 2, 2], n = 5
//Return 0.


//这题是这样的，我们假设 miss表示当前为止我们第一个不能表示的数， 一开始miss设为1，如果num <= miss, 那么我们可以表示的数为[0,num+miss). 如果num > miss或者数组没有数了,我们需要补一个数miss. 这样我们下一次继续访问num,继续判断，直到miss > n位置。 

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int res = 0, i = 0;
        while(miss <= n) {
            
            if(i < nums.size() &&nums[i] <= miss) {
                miss += nums[i];
                ++i;
            }
            else {
                miss<<=1; 
                res ++;
            }
        }     
        return res;
    }
};