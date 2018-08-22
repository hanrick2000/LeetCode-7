//  只要把输入的数字全部倒过来即可   注意点    溢出判断：(res > INT_MAX/10&&x)||(res == INT_MAX/10&&x%10>cut)  即当前数已经大于MAX/10  并且x还有位，或者当前数等于MAX/10  x的下一位大于MAX%10.
//
//
class Solution {
public:
    int reverse(int x) {
        
        if(x==INT_MIN) return 0;
        
        bool pos = x>0;
        x = pos?x:-x;
        
        int cut = pos?INT_MAX%10:INT_MAX%10+1;
    
        int res = 0;
        
        while(x) {
            res = res*10 + x%10;
            x/=10;
            if((res > INT_MAX/10&&x)||(res == INT_MAX/10&&x%10>cut)) {
                return 0;
            }
        }
        return pos?res:-res;
    }
};

再改版，其实负数倒过来不用转成正数做。C/C++的除法是向零靠，即  -7/4 = -(7/4) = -1 
-321%10 = -1;  依然还是 res*10 + -1 = -1   -321/10 = -32;
-32%10 = -2; 依然还是 res*10 + -2 = -12 -32/10 = -3;
-3%10 = -3; 依然还是 res*10 + -3 = -123 -3/10 = 0;

再来说一说溢出。。正数要判断  res*10 + x%10 > INT_MAX即  res > (INT_MAX - x%10)/10)   负数要判断   res*10 + x%10 < INT_MIN 即 res < (INT_MIN - x%10)/10) 
    

class Solution {
public:
    int reverse(int x) {
      
        int res = 0;
 
        while(x) {
            
            if(res > 0 && res > (INT_MAX - x%10)/10)    return 0;
            
            if(res < 0 && res < (INT_MIN - x%10)/10)    return 0;
            
            res = res*10 + x%10;
            x/=10;
        }
        
        return res;
        
    }
};


