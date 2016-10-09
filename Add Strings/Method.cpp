//Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.
//
//Note:
//
//The length of both num1 and num2 is < 5100.
//Both num1 and num2 contains only digits 0-9.
//Both num1 and num2 does not contain any leading zero.
//You must not use any built-in BigInteger library or convert the inputs to integer directly.

//按标准的string + string 做法来做。

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        if(num1.size() < num2.size()) swap(num1,num2);     
        int p = int(num1.size())-1, q = int(num2.size())-1;
        
        int carry = 0;
        while(p >= 0 && q >= 0) {
            
            int tmp = num1[p] - '0' + carry + num2[q] - '0';
            num1[p] = tmp%10 + '0';
            carry = tmp>=10?1:0;
            --p;--q;
        }
        
        while(p >= 0) {
            
            int tmp = num1[p] - '0' + carry;
            
            num1[p] = tmp%10 + '0';
            carry = tmp>=10?1:0;
            --p;
        }
        
        if(carry) num1 = "1" + num1; 
        return num1;
        
    }
};