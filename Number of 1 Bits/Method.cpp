//Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
//
//For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

//这题在数1，最常规的做法是循环右移，直到数为0，每一次取最右一位是不是1.
//还有更加黑客的做法，每一次循环可以把n最右的1给清0，就是n与上n-1.假设n最后一位1在k，10000， 那么n-1这几位为01111,正好把这里清零。

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int val = 0;
        while(n) {
            if(n&1) ++val;
            n>>=1;
        }
        return val;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        while(n) {
            
            n = n&n-1;
            count++;
        }
        return count;
        
        
    }
};