//可以用longlong的话  我们就可以将参数全部转化为正数。然后根据符号返回结果，不用再为溢出而额外判断。

class Solution {
public:

    int divide(int dividend, int divisor) {

        if(!divisor) return INT_MAX;  //overflow 两种
        if(dividend == INT_MIN&&divisor == -1) return INT_MAX; //overflow 两种
        
        if(!dividend) return 0;
        
        
        bool pos1 = dividend>0, pos2 = divisor>0;
        long long g = divisor, p = dividend, g_copy, count = 1;
        
        if(!pos1) {
            p = -p;
        }
        if(!pos2) {
            g = -g;
        }
        
        g_copy = g;
        if(g > p) return 0;
            
        while(g+g<= p ) {
            g+=g;
            count+=count;
        }
            
        return pos2==pos1?(count + divide(p-g,g_copy)):-(count + divide(p-g,g_copy));

    }
};


    long long dividePos(long long d1, long long d2) {
        
        if(d1 < d2) return 0;
        
        long long sum = 0, d = d2;
        while(d1 >= d) {
            
            d1 -= d;
            sum += (sum+1);
            d <<= 1;
        }
        
        return sum + dividePos(d1, d2);
    }
    
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        long long d1 = dividend, d2 = divisor;

        bool neg = (d1 < 0) ^ (d2 < 0);
        d1 = d1 < 0 ? -d1 : d1;
        d2 = d2 < 0 ? -d2 : d2;
        
        long long res = dividePos(d1, d2);

        if(neg) {
            return -res < INT_MIN ? INT_MAX : -res;
        }
        
        return res > INT_MAX ? INT_MAX : res;
    }