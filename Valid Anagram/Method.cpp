//Given two strings s and t, write a function to determine if t is an anagram of s.
//
//For example,
//s = "anagram", t = "nagaram", return true.
//s = "rat", t = "car", return false.
//
//Note:
//You may assume the string contains only lowercase alphabets.
//
//Follow up:
//What if the inputs contain unicode characters? How would you adapt your solution to such case?

//傻逼题，
//unicode的话要按照一种编码方式解码，得到code point,然后建立hashmap.

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int a[26];
        
        memset(a,0,sizeof(a));
        // memset(b,0,sizeof(b));
        
        
        for(auto x: s) {
            ++a[x-'a'];
        }
        
        for(auto x: t) {
            if(--a[x-'a'] < 0) return false;
        }
        
        for(auto x: a) {
            if(x) return false;
        }
        
        return true;
    }
};