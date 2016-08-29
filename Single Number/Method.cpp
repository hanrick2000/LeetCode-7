//Given an array of integers, every element appears twice except for one. Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

//所有数异或，成双入对的数异或全0,0与单数异或就是那个数。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        
        for(int i = 1; i < nums.size(); ++i) {
            res^=nums[i];
        }
        return res;
        
    }
};

