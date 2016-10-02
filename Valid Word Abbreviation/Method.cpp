//Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.
//
//A string such as "word" contains only the following valid abbreviations:
//
//["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
//Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".
//
//Note:
//Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.
//
//Example 1:
//Given s = "internationalization", abbr = "i12iz4n":
//
//Return true.
//Example 2:
//Given s = "apple", abbr = "a2e":
//
//Return false.

//这题直接顺序匹配下来，注意0不能出现在数字的开头，并且最后注意匹配完匹配不完整，都要返回false.


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
};