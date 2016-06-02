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