//Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
//This is case sensitive, for example "Aa" is not considered a palindrome here.
//
//Note:
//Assume the length of given string will not exceed 1,010.
//
//Example:
//
//Input:
//"abccccdd"
//
//Output:
//7
//
//Explanation:
//One longest palindrome that can be built is "dccaccd", whose length is 7.

//hash表记录字符出现个数，最大长度可以把所有的偶数加起来，奇数次数允许加至多一次，剩下的奇数得-1后加起来。。

class Solution {
public:
    int longestPalindrome(string s) {
      
        vector<int> mymap(128,0);
        
        for(auto x: s)  ++mymap[x];

        int res = 0;
        
        for(auto x: mymap) {
            
            if(x%2) res += res%2? x-1: x;
        
            else res += x;
        }

        return res;
    }
};

