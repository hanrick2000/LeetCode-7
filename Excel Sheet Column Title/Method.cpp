//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example:
//
//    1 -> A
//    2 -> B
//    3 -> C
//    ...
//    26 -> Z
//    27 -> AA
//    28 -> AB 

//找出规律来，更习惯把[0...25]映射给［A...Z］因为除以26所得的除数都是0，否则还要对26这个数额外讨论，循环每一次将(n-1)%26 所映射的字母映射给res的末尾，
//    
//如AAA == 703 ＝ 27*26+1， 第一次循环  n自减1，余26，映射最后一位a，然后除以26后接下去映射剩下的数，27 ＝ 1*26 + 1 进循环  映射A, 除26.
    

class Solution {
public:
    string convertToTitle(int n) {

        string res;

        while(n--) {
            res=char(n%26+'A')+res;
            n = n/26;
        }
        
        return res;
    }
};