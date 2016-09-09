//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
//
//For example:
//
//Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
//
//Note:
//The order of the result is not important. So in the above example, [5, 3] is also correct.
//Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

//这题的思路是：先把所有数亦或，答案肯定不是零，因为有两个不相等的数异或，它们二进制位肯定有一位不同，所以我们在亦或结果里面找到该位，然后在原始数组里面依据该位的掩码（即其它位全零，该位为1）来把这些数分成两半，这样这两个数就被分开了。分开后一异或就都出来了。
    
    

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int tmp=0;
        for(auto x: nums) {
            tmp^=x;
        }
        
        tmp&=(-tmp);
        
        int a = 0, b = 0;
        
        for(auto x: nums) {
            if(x&tmp) {
                a^=x;
            }
            else {
            
                b^=x;
            }
        }
            
        return {a,b};
        
    }
};