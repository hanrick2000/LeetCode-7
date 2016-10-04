//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.
//
//Examples:
//pattern = "abab", str = "redblueredblue" should return true.
//pattern = "aaaa", str = "asdasdasdasd" should return true.
//pattern = "aabb", str = "xyzabcxzyabc" should return false.
//Notes:
//You may assume both pattern and str contains only lowercase letters.

用dfs + 回溯  +hashmap完成

class Solution {
public:
    
    bool dfs(string& pattern, string &str, int p_begin, int s_begin, vector<string> &p2s, unordered_map<string, char> &s2p) {
        if(p_begin == pattern.size() && s_begin == str.size()) return true; 
        if(p_begin == pattern.size() && s_begin != str.size()) return false;
        if(p_begin != pattern.size() && s_begin == str.size()) return false;
                
                
        if(p2s[pattern[p_begin]-'a'] != "") {
            
            string t = p2s[pattern[p_begin]-'a'];
            
            if(str.substr(s_begin, t.size()) == t) return dfs(pattern, str, p_begin+1, s_begin + t.size(), p2s, s2p);
            
            return false;
        }
        
        string t;
        for(int i = s_begin; i < str.size(); ++i) {
            
            t+=str[i];
            
            if(s2p.find(t)!=s2p.end()) continue;
            
            s2p[t] = pattern[p_begin];
            p2s[pattern[p_begin]-'a'] = t;
            
            if(dfs(pattern, str, p_begin+1, s_begin + t.size(), p2s, s2p)) return true;
            
            s2p.erase(t);
            p2s[pattern[p_begin]-'a'] = "";
            
        }

        return false;
    }
    
    
    bool wordPatternMatch(string pattern, string str) {

        vector<string> p2s(26,"");
        
        unordered_map<string, char> s2p;
        
        return dfs(pattern, str, 0, 0, p2s, s2p);
        
    }
};