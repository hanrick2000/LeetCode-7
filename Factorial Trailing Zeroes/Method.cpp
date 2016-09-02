//Given an integer n, return the number of trailing zeroes in n!.
//
//Note: Your solution should be in logarithmic time complexity.


//这题其实就问1到n有多少5的因子，5算一次，25算两次，125算3次。。。我们可以求出这期间5的倍数个数，加上25倍数个数，加上125倍数个数。为啥呢？因为对于25来说，在5的倍数个数是算过一次，在25的倍数个数时又算过一次，正好。以此类推。千万注意溢出问题！

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0,prime = 1;
        
        while(n/5>=prime) {
            
            prime*=5;
            result+=n/prime;
            
        }

        return result;
    }
};