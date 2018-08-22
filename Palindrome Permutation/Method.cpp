//Given a string, determine if a permutation of the string could form a palindrome.
//
//For example,
//"code" -> False, "aab" -> True, "carerac" -> True.
//
//Hint:
//
//Consider the palindromes of odd vs even length. What difference do you notice?
//Count the frequency of each character.
//If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?

//很明确，数词频，偶数项肯定没问题，奇数项就只能出现一次。

class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        int a[128];
        memset(a,0,sizeof(a));
        
        for(int i = 0; i < s.size(); ++i) {
            
            ++a[s[i]];
            
        }
        int single = 0;

        for(int i = 0; i <128; ++i) {
            if(a[i]%2) ++single;
            if(single > 1) return false;
        }
        
        
        return true;
    }
    
    bool canPermutePalindrome(string s) {
        
        vector<int> mymap(128,0);
        int odd = 0;
        for(char &c: s) {
            if((++mymap[c])&1) ++odd;
            else --odd;
        }
        
        return odd <=1;
    }
};