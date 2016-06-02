//此方法类似于用两个指针一头一尾往中间靠判断回文。O(n)

class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0) return false;
        
        int high = 1,low = 1;
        
        while(x/high>=10) {
            high *=10;
        }
        
        while(high>low) {
            
            if((x/low)%10!=(x/high)%10) return false;
            high/=10;
            low*=10;
        }
        
        return true;
        
    }
};