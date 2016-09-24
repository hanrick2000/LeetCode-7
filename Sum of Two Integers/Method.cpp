//Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
//
//Example:
//Given a = 1 and b = 2, return 3.

我们可以假象一下，两个数二进制位相加就是所有数位摸2加 加上所有进位。

class Solution {
public:
    int getSum(int a, int b) {
        
        if(b == 0) return a;
        
        int v = a^b; //所有  数位模2和，
        int carry = (a&b)<<1; //所有进位

        return getSum(v,carry);  //递归  ，因为没调用一次carry想左一以为，32次之后总会全0的
        
        
    }
};