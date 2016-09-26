//Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
//
//Example1:
//
//a = 2
//b = [3]
//
//Result: 8
//Example2:
//
//a = 2
//b = [1,0]
//
//Result: 1024

这题不过是十进制版的pow(x,n). 例如a^431  可以拆分为((a^4)^10*a^3)^10*a^1.每一个10次方都可以再写一个函数用2次方完成。这个函数可以用递归，这样省的把2进制倒过来。


class Solution {
public:

    int power(int base, int pow = 10, int mode = 1337) {
        
        if(!pow) return 1;
        
        int b = power(base, pow>>1);
        
        if(pow%2) return (b*b%mode)*(base%mode)%mode;
        
        return b*b%mode;
    }

    int superPow(int a, vector<int>& b) {
    
        int tmp = 1;
        
        for(auto x: b) {
            
            tmp = power(tmp);
            
            tmp*= power(a,x);
            
            tmp%=1337;
        }
        
        return tmp;
    }
};