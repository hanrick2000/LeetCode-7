//Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//
//Return true because "leetcode" can be segmented as "leet code".


//这题思路很简单，从位置0开始，判断s[i]是不是true，判断方法是用一个dp数组纪录dp[i]==true 当且仅当s[0...i]是true，从0到i,如果s[i..j]是单词且s[0...j]是true。
//但有个很快的方法，我们可以扫描时记录下true的那些索引，等下次扫描时时间判断这些索引到i是不是单词，就快很多了

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        
        
        vector<int> opt = {-1};  // j record that s[0:j] is true.
        
        for(int i = 0; i<s.size(); ++i) {
            
            for(int j = opt.size()-1; j > -1; --j) {
                
                if(wordDict.find(s.substr(opt[j]+1,i-opt[j]))!=wordDict.end()) {
                    opt.push_back(i);
                    break;
                }
            }
            
        }
        
        return opt.back() == s.size()-1;
        
    }
};