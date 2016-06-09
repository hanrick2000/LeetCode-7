//The count-and-say sequence is the sequence of integers beginning as follows:
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.



//没啥好说的

class Solution {
public:
    
    string countAndSay(int n) {
        string s = "1";
        
        for(int i = 1; i < n; ++i) {
            int count = 1;
            string temp;
            for(int j = 1; j < s.size(); ++j) {
                if(s[j] == s[j-1]) count++; 
                else {
                    temp+=to_string(count) + s[j-1];
                    count = 1;   //容易忘
                }
            }
            temp+=to_string(count) + s.back();  //更容易忘
            s = temp;
        }
        return s;
    }
};