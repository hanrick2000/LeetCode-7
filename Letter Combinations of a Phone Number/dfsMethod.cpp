//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below.
//
//
//
//Input:Digit string "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

//本题是标准的dfs做法。


class Solution {
public:

    void dfs(int depth, string &s, vector<string>& res, string table[], string cur) {
        if(depth == s.size()) {
            res.push_back(cur);
            return;
        }
        
        for(auto &x: table[s[depth]-'0']) {
            dfs(depth+1,s,res,table,cur+x);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        string table[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        vector<string> res;
        
        dfs(0,digits,res,table,"");
        
        return res;
    }
};