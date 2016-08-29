//Given an array of integers, every element appears three times except for one. Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

//可以想到，所有数都是3k个时，在某一二进制位上1的个数和0的个数应当是3k，现在加一个数，那么这一位要么是0要么是1，所以个数为3k+1的那一个就是这个数第i位上的值。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int mask = 1, res = 0;
        for(int i = 0; i < 32; ++i) {
            int count = 0;
            for(int j = 0; j < nums.size(); ++j) {
                if(nums[j]&mask) ++count;
            }
            if(count%3) {
                res |= mask;
            }
            mask <<= 1;
        }
        
        
        return res;
    }
};