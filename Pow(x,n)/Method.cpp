//Implement pow(x, n).


//基本做法是使用二分法，即对指数用二进制表示，从最高位1开始，遇到一个1 ，res平方＊底数，遇到一个0，res平方。因此我们不妨将指数化为正数，如果是负数，到时求倒数即可。
//但是有很多细节和边角需要考虑，1)乘积溢出？ 索性c++ 里面double超出表示范围， 会自动转化为inf或-inf; 2)将负数变为正数永远要考虑INT_MIN的情况。可以用long long苟且偷生。或者也可以拆分成-(INT_MIN+1) 和 1.1的话最后再乘一下即可。

class Solution {
public:
    double myPow(double x, int n) {
        
        int n_copy = n;
        
        if(n<0)  {
            if(n == INT_MIN)  n_copy = -(n+1);
            else n_copy = -n_copy;            
        }

        stack<int> mystack;
        double result = 1;
        while(n_copy) {
            mystack.push(n_copy&1);
            n_copy = n_copy>>1;
        }
        
        while(mystack.size()) {
            int temp = mystack.top();
            result*=result;
            
            if(temp) {
                result*=x;
            }
            mystack.pop();
        }
        
        if(n == INT_MIN) result*=x;
        
        if(n<0) result = 1/result;
        
        return result;
        
    }
    
    double helper(double x, long long n) {
        if(n == 0) return 1;
        
        if(n < 0) return 1.0/helper(x, -n);
        
        double res = helper(x,n>>1);
        
        return n&1? x * res * res: res * res;
    }
    
    double myPow(double x, int n) {
        return helper(x,n);
    }
};