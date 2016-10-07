//A string such as "word" contains the following abbreviations:
//
//["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
//Given a target string and a set of strings in a dictionary, find an abbreviation of this target string with the smallest possible length such that it does not conflict with abbreviations of the strings in the dictionary.
//
//Each number or letter in the abbreviation is considered length = 1. For example, the abbreviation "a32bc" has length = 4.
//
//Note:
//In the case of multiple answers as shown in the second example below, you may return any one of them.
//Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.
//Examples:
//"apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")
//
//"apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").


//其实就是valid Word Abbreviation和Generalized Abbreviation的组合，
//先生成缩写，然后搜索的时候记录一个压缩指数。压缩指数最大的就可以了。最后返回一个最优解。

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        
        int p = 0;
        
        for(int i = 0; i < abbr.size(); ++i) {
            
            if(abbr[i]>='0'&&abbr[i]<='9') {
                int tmp = 0;
                
                if(abbr[i] == '0') return false;
                
                while(i < abbr.size()&&abbr[i]>='0'&&abbr[i]<='9') {
                    tmp = tmp*10 + abbr[i] - '0';
                    ++i;
                }
                --i;
                
                p += tmp;
                if(p > word.size()) return false;
            }
            
            else {
                if(p >= word.size() || word[p]!=abbr[i]) {
                    return false;
                }
                ++p;
            }
        }   
        return p == word.size();
        
    }
    
    void generateAbbreviationsHelper(string &word, string &res, string cur , int start, vector<string>& dictionary, int modi, int &maxi) {
        
        if(start >= word.size()) {

            for(auto x: dictionary) {
                if(validWordAbbreviation(x, cur)) return ;
            }
            
            if(modi > maxi) {
                res = cur;
                maxi = modi;
            }
            return ;
        }
        
        generateAbbreviationsHelper(word, res,cur + word[start], start+1, dictionary, modi, maxi);
        
        for(int i = start; i < word.size(); ++i) {
            
            string tmp;
            if(i<word.size()-1) tmp  = word[i+1];
            generateAbbreviationsHelper(word, res, cur+ to_string(i-start+1) + tmp, i+2, dictionary, modi+ i-start, maxi);
        }
        
    }

    string minAbbreviation(string target, vector<string>& dictionary) {
        string res;
        string cur;
        int maxi = -1;
        generateAbbreviationsHelper(target, res, cur, 0, dictionary, 0, maxi);
        return res;
    }
};