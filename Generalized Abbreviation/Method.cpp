//Write a function to generate the generalized abbreviations of a word.
//
//Example:
//Given word = "word", return the following list (order does not matter):
//["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]


这题得这样dfs递归：

f(abc):  当start = 0时
    

"a" + f("bc")
"1b" + f("c")
"2c" + f("")
"3" + f("")
    
//一定要保证前缀不同，才不会重复，而且，1，2时一定要跟着后面的b，c，不然你会出现11c这种怪胎。


class Solution {
public:

    void generateAbbreviationsHelper(string &word, vector<string> &res, string cur , int start) {
        
        if(start >= word.size()) {
            res.push_back(cur);
            return;
        }

        generateAbbreviationsHelper(word, res,cur + word[start], start+1);
        
        for(int i = start; i < word.size(); ++i) {
            
            string tmp;
            if(i<word.size()-1) tmp  = word[i+1];
            
            generateAbbreviationsHelper(word, res, cur+ to_string(i-start+1) + tmp, i+2);
        }
    }

    vector<string> generateAbbreviations(string word) {
        
        vector<string> res;
        string cur;
        generateAbbreviationsHelper(word, res, cur, 0);
                
        return res;
    }
};