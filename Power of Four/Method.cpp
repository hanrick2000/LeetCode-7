//Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
//
//Example:
//Given num = 16, return true. Given num = 5, return false.
//
//Follow up: Could you solve it without loops/recursion?

//先确定num只有一个1， 然后再确认它的1必须得出现在偶数位，

class Solution {
public:
    bool isPowerOfFour(int num) {
        
        return (num&(-num)) == num && num&0b01010101010101010101010101010101;
        
    }
};

