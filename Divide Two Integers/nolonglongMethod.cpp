//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.

//不用long long 当被除数是INT_MIN 真的很麻烦，完全得为他另外写一个else语句。总之  思路就是二分法找到与被除数最接近的除数，然后得到部分商，再递归的用剩下的数除以被除数，将部分商相加。

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor) return INT_MAX;  //overflow 两种
        if(dividend == INT_MIN&&divisor == -1) return INT_MAX; //overflow 两种
        
        if(divisor == INT_MIN) return dividend == INT_MIN;
        
        if(!dividend) return 0;
        
        bool pos1 = dividend>0, pos2 = divisor>0;
        
        if(!pos2) {
            divisor = -divisor;
        }
        
        int g = divisor, count = 1;
        
        
        if(pos1) {
            if(g > dividend) return 0;
            
            while(g<(INT_MAX>>1)&&g+g<= dividend ) {
                g+=g;
                
                count+=count;
            }
            
            return pos2?(count + divide(dividend-g,divisor)):-(count + divide(dividend-g,divisor));
        }
        
        else {
            if(dividend + g > 0) return 0;
            
            while(dividend+g+g<=0) {
                if(dividend+g+g==0) {
                    count+=count;
                    g+=g;
                    break;
                }
                g+=g;
                count+=count;
            }
            return pos2?-(count + divide(-g-dividend,divisor)):(count + divide(-g-dividend,divisor));
        }

    }
};