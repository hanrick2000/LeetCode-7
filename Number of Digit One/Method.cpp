//Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
//
//For example:
//Given n = 13,
//Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
//
//Hint:
//
//Beware of overflow.

//对每一个位进行统计，第i位(假设百位)， 如果
//i百位是0, 等于大于百位的数*100
//ii)百位是1，等于大于百位的数*100 + 小于百位的数+1
//iii)百位大于1   等于（大于百位的数+1）*100
//    
//testcase 1,10,100等，要注意溢出问题

class Solution {
public:
    int countDigitOne(int n) {

        int res = 0, a = 1;
        while(n>=a)  {

            if((n/a)%10 < 1) {
                res+= n/a/10*a;
            }
            
            else if ((n/a)%10 > 1) {
                
                res+= (n/a/10 + 1)*a;
            }
            
            else {
                res+= n/a/10*a + n%a+1;
                
            }
            if(a>=INT_MAX/10) break;
            a*=10;   

        }
        return res;
        
    }
};