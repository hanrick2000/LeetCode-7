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