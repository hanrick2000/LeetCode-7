//该方法将x反过来构造一遍。但是不用考虑溢出问题。因为如果本身是回文数 那么肯定不会溢出 返回true。
class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0) return false;
        
        int xx = x,res = 0;
        while(xx) {
            if(res > (INT_MAX - xx%10)/10) return false;
            res = res*10+xx%10;
            xx/=10;
        }
        
        return res == x;
        
    }
};