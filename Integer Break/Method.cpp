//Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
//
//For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
//
//Note: You may assume that n is not less than 2 and not larger than 58.
//
//Hint:
//
//There is a simple O(n) solution to this problem.
//You may check the breaking results of n ranging from 7 to 10 to discover the regularities.


//找规律，能被三整除就3连乘，余2就再乘2，余1就少一个3乘4.

class Solution {
public:
    int integerBreak(int n) {

        if(n == 2) return 1;
        if(n == 3) return 2;
        
        int k = n/3, j = 1;
        
        for(int i = 0; i < k; ++i) {
            j*=3;
        }
        
        if(n%3 == 2) j*=2;
        
        if(n%3 == 1) j=j/3*4;
        
        return j;
        
    }
};