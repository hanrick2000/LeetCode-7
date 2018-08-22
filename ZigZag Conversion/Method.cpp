//此方法 按行打，从s[0]到s[2（n-1）－1]公2（n-1）个数为一个循环。
//复杂度O(n), 空间O(n).

//P   A
//A P
//Y


class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows==1) return s; 
        string rst;
        int cons = 2*numRows-2;
       
        for(int i = 0; i < numRows; ++i) {
            for(int j = i,cut = j+cons-2*i; j < s.size(); j+=cons,cut+=cons) {
                rst+=s[j];
                if(i > 0 && i < numRows-1&&cut<s.size() ) {
                    rst+= s[cut];
                }
            }
        }
        
        return rst;
        
    }
};