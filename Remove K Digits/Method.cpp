//Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//Note:
//The length of num is less than 10002 and will be ≥ k.
//The given num does not contain any leading zero.
//Example 1:
//
//Input: num = "1432219", k = 3
//Output: "1219"
//Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//Example 2:
//
//Input: num = "10200", k = 1
//Output: "200"
//Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
//Example 3:
//
//Input: num = "10", k = 2
//Output: "0"
//Explanation: Remove all the digits from the number and it is left with nothing which is 0.

这题是贪心法 每一次来说
i)如果第二个数是0,肯定删除第一个数
ii)顺着找到第一个比前一个数小的数字，然后删除这个数字的前面那个数。如12342  就删除4.
循环k次，只要中间变成0就要跳出

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        while(k-->0&&num!="0") {

            if(num.size()>1&&num[1] == '0') {
                int p = 2;
                while(num[p] == '0') {
                    ++p;
                }
                
                num = num.substr(p);
            }
            
            else {
                
                int i = 1;
                for(; i < num.size(); ++i) {
                    
                    if(num[i] < num[i-1]) {
                        --i;
                        break;
                    }
                }
                
                if(i == num.size()) --i;

                num.erase(num.begin()+i);
            }
            if(num == "") num = "0";
            
        }
        
        return num;
        
        
    }
};