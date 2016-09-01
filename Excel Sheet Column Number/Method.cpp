//Related to question Excel Sheet Column Title
//
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example:
//
//    A -> 1
//    B -> 2
//    C -> 3
//    ...
//    Z -> 26
//    AA -> 27
//    AB -> 28 

//非常简单，顺序读入，每一次读到一个字母，res*26 + 该字母对应的数字

class Solution {
public:
    int titleToNumber(string s) {
        
        
        int res = 0;
        for(int i = 0; i < s.size(); ++i) {
            res = 26*res + s[i]+1-'A';
        }
        return res;
    }
};