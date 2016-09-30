//Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
//
//Note:
//n is positive and will fit within the range of a 32-bit signed integer (n < 231).
//
//Example 1:
//
//Input:
//3
//
//Output:
//3
//Example 2:
//
//Input:
//11
//
//Output:
//0
//
//Explanation:
//The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.


分为三步，第一步求出它是几位数，一位数共有9个数字，二位数共有90*2个数字。。。
第二步求出它是哪个数。 第三步求出它是这个数哪一位数字。注意溢出。。。

class Solution {
public:
    int findNthDigit(int n) {
        
        long long m = 9, len = 0 ,n1 = n;
        
        while (n1 > 0) {
            ++len;
            n1 -= len * m;
            m*=10;
        }
        
        n1 += len*m/10;
        
        long long t = 1;
        for(int i = 0; i < len-1-(n1-1)%len; ++i) {
            t*=10;
        }
        
        return ((m/90+(n1-1)/len)/t)%10;
    }
};