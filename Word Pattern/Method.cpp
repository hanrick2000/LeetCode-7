//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
//Examples:
//pattern = "abba", str = "dog cat cat dog" should return true.
//pattern = "abba", str = "dog cat cat fish" should return false.
//pattern = "aaaa", str = "dog cat cat dog" should return false.
//pattern = "abba", str = "dog dog dog dog" should return false.
//Notes:
//You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

也是两个map互相映射，形成一一对应。还有几个特殊条件pattern和str"size"要相等

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        int j = 0;
        str += " ";//方便处理最后一个单词
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        
        string tmp;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i]!=' ') tmp += str[i];
            else {
                if(j >= pattern.size()) return false;
                
                if(m1.find(pattern[j])!=m1.end()) {
                    if(m1[pattern[j]] != tmp) return false;
                    
                }
                else {
                    m1[pattern[j]] = tmp;
                }
                
                if(m2.find(tmp)!=m2.end()) {
                    if(m2[tmp] != pattern[j]) return false;
                    
                }
                else {
                    m2[tmp] = pattern[j];
                }
                
                ++j;
                
                tmp = "";
            }
        }
        
        return j == pattern.size();
    }
};