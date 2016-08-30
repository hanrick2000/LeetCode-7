//Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
//
//Return all such possible sentences.
//
//For example, given
//s = "catsanddog",
//dict = ["cat", "cats", "and", "sand", "dog"].
//
//A solution is ["cats and dog", "cat sand dog"].


不能单单的递归dfs，会超时。我们要继续利用dp,设一个opt数组，纪录所有可以切开来的位置。
然后进行dfs,用一个二维vector<string>纪录每一个位置上的结果，以便被后期利用。


class Solution {
public:

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        
        vector<int> opt = {-1};  // j record that s[0:j] is true.
        
        for(int i = 0; i<s.size(); ++i) {
            
            for(int j = opt.size()-1; j > -1; --j) {
                
                if(wordDict.find(s.substr(opt[j]+1,i-opt[j]))!=wordDict.end()) {
                    opt.push_back(i);
                    break;
                }
            }
            
        }
        
        if(opt.back() != s.size()-1) return {};
        
        
        vector<vector<string>> mem={{""}};
        opt = {-1};
        
        for(int i = 0; i<s.size(); ++i) {
            int count = 0;
            vector<string> tmp;
            for(int j = opt.size()-1; j > -1; --j) {
                
                if(wordDict.find(s.substr(opt[j]+1,i-opt[j]))!=wordDict.end()) {
                    if(!count) {
                        opt.push_back(i);
                        ++count;
                        
                    }
                    
                    for(int k = 0; k < mem[opt[j]+1].size(); ++k) {
                        
                        if(mem[opt[j]+1][k]!="") tmp.push_back(mem[opt[j]+1][k]+" "+s.substr(opt[j]+1,i-opt[j]));
                        else tmp.push_back(mem[opt[j]+1][k]+s.substr(opt[j]+1,i-opt[j]));
                        
                    }
                    
                }
                
            }
            
            mem.push_back(tmp);
            
        }
        
        
        return mem.back();
    }
};