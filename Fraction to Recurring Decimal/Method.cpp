//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
//If the fractional part is repeating, enclose the repeating part in parentheses.
//
//For example,
//
//Given numerator = 1, denominator = 2, return "0.5".
//Given numerator = 2, denominator = 1, return "2".
//Given numerator = 2, denominator = 3, return "0.(6)".
//Hint:
//
//No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
//Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
//Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.

//这题首先得考虑 INT_MIN,   没辙就先用long long。第二点是如何确定循环节？ 被除数重复的时候说明循环出现了，循环的位置用一个hashmap记录。最后要注意那个符号和点号。


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if(!numerator) return "0";
        long long num = numerator, den = denominator;
        
        bool pos = (numerator>0)^(denominator>0);
        
        num =  num>0?num:-num;
        den = den>0? den:-den;
        
        long long quota = num/den;
        
        string res;
        
        unordered_map<int,int> mymap;
        
        num = num%den;
        
        while(num) {
            
            if(mymap.find(num)!=mymap.end()) {
                res.insert(mymap[num],"(");
                res += ')';
                break;
            }
            
            mymap[num] = res.size();
            num*=10;
            
            res+= char(num/den+'0');
            
            num = num%den;
        }
        
        res = res==""? to_string(quota)  +  res: to_string(quota) + "."+  res;
        
        res = pos?"-"+res:res;
        return res;
         
    }
};