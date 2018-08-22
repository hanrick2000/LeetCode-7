//Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
//For example, given the range [5, 7], you should return 4.

//从32位的每一位开始，比较m和n的该位，如果至少有一个是0，那结果的该位就是0，否则，考虑这两位1中间会不会出现过0， 这就表示m和n之间一定会经过某一个数，它能整除这一位所表示的二进制数，那么n除以它的值一定大于m除以这个数的值


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        for(int i = 1; i>0; i<<=1) {
            if(m&&n) {
                if(n/i > m/i) {
                    n&=(~i);  //clear to 0
                }
            }
            
            else {
                n&=(~i);  //clear to 0
            }
            if(i>n) break;
            
        }
        
        
        return n;
    }
};