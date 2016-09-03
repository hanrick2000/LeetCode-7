//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
//For example,
//Given "egg", "add", return true.
//
//Given "foo", "bar", return false.
//
//Given "paper", "title", return true.


//这题要保证s->t, t->s都是一一映射. 所以要两个hashmap,都是字符，可以用char array来表示。

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        char s_to_t[128], t_to_s[128];
        memset(s_to_t, 0, sizeof(s_to_t));
        memset(t_to_s, 0, sizeof(t_to_s));
        
        for(int i = 0; i < s.size(); ++i) {
            
            if(s_to_t[s[i]]) {
                if(s_to_t[s[i]]!=t[i]) return false;
            }
            else {
                s_to_t[s[i]] = t[i];
            }
            
            if(t_to_s[t[i]]) {
                if(t_to_s[t[i]]!=s[i]) return false;
            }
            else {
                t_to_s[t[i]] = s[i];
            }
            
        }
        
        return true;
    }
};
