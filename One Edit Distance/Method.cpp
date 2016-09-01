//Given two strings S and T, determine if they are both one edit distance apart.

//这题首先确保s比t长。然后剔除s长度大于t2以上的。然后进入大循环（默认s比t长1或相等），如果有一个字符不一样，立刻比较s该字符之后的子串和t该字符开始的子串，相等与否或者该字符开始的两个子串是否相等。
//    
//如果能跳出循环，最后别忘了s可能还有一个字符没有比较，返回两个字符串长度是否不等。


class Solution {
public:
    bool isOneEditDistance(string s, string t) {

        if(s.size() < t.size()) {
            swap(s,t);
        }
        
        if(s.size()-t.size()>1) return false;
        
        for(int i = 0; i < t.size(); ++i) {
            if(s[i]!=t[i]) {
                return t.substr(i,t.size()-i) == s.substr(i+1,s.size()-i-1) || s.substr(i+1,s.size()-i-1) == t.substr(i+1,t.size()-i-1);
            } 
        }
        
        return s.size() != t.size();
        
    }
};