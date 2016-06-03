// 匹配s和p，对于p来说 有四种可能
// 1) 空串： s也要空串才匹配
// 2) 一个字符， s也要一个字符，并且两个字符一样或p的字符是'.'
// 3) 至少两个字符，第二个字符不是'*', 第一个字符得匹配，然后在递归处理s[1:] 和 p[1:]
// 4) 至少两个字符，第二个字符是'*', 然后如果s[0]开始的几个字符如果都可以和p[0]匹配，递归匹配，也可以不匹配s[0]。
//
class Solution {
public:
    bool isMatch(string s, string p) {
        
        if(p == "") return s == ""; 
        
        if(p.size()<2) {
            if(s == "") return false;
            if(s.size()>1) return false; 
            
            return p[0] == s[0]||p[0] == '.';
        }
        
        if(p[1] != '*') {
            if(s == "") return false;
            if(p[0] == s[0]||p[0] == '.') {
                return isMatch(s.substr(1,s.size()-1),p.substr(1,p.size()-1));
            }
            return false;
        }
        
        int i = 0;
        while(i<s.size()&&(s[i] == p[0]||p[0] == '.')) {
            if(isMatch(s.substr(i+1,s.size()-1-i),p.substr(2,p.size()-2)))
                return true;
            i++;
        }

        return isMatch(s.substr(0,s.size()),p.substr(2,p.size()-2));
        
    }
};