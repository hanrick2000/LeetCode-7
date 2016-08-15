//The gray code is a binary numeral system where two successive values differ in only one bit.
//
//Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
//
//For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//
//00 - 0
//01 - 1
//11 - 3
//10 - 2
//Note:
//For a given n, a gray code sequence is not uniquely defined.
//
//For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
//
//For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.



//这题可以通过找规律出来， 

//
//n = 1   ||    n = 2   ||    n = 3
//0             00
//1             01
//              11
//              10

//n=k相当于 前2^(k-1) 个数与n=k-1结果一样，剩下2^(k-1)个数相当于逆序的在之前的结果加上高位的1.


class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> res = {0};
        
        int k = 1;
        
        for(int i = 0; i < n; ++i) {
            
            for(int j = k-1; j > -1; --j) {
                res.push_back(res[j]+k);
                
            }
            k<<=1;
        }
        
        return res;
              
    }
};