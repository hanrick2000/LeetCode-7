//Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
//Examples:
//
//s = "leetcode"
//return 0.
//
//s = "loveleetcode",
//return 2.
//Note: You may assume the string contain only lowercase letters.

//无语  直接hash 

class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> visited(26,false); 
    
        for(int i = 0; i < s.size(); ++i) {
            ++visited[s[i]-'a'];
        }
        
        for(int i = 0; i < s.size(); ++i) {
            if(visited[s[i]-'a'] == 1) return i;
        }

        return -1;
    }
};