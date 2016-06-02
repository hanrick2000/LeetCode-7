// 该方法类似于快指针和满指针。  设计一个/100的式子可以娶到整数的后1/2位，而且可以反过来造，这个数和我们的x正好有关系（取决于奇数位长度还是偶数位长度）。
//
class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0) return false;
        
        int xx = x,res = 0;
        
        while(xx) {
            res = res*10 + x%10;
            x/=10;
            xx/=100;
        }
        
        return res == x||res/10 == x;
    }
};