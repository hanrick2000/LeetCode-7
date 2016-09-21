//Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
//
//Example 1:
//Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//Return 16
//The two words can be "abcw", "xtfn".
//
//Example 2:
//Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//Return 4
//The two words can be "ab", "cd".
//
//Example 3:
//Given ["a", "aa", "aaa", "aaaa"]
//Return 0
//No such pair of words.

这题用一个位来表示一个字母是否在单词中出现，即26位的整数就可以表示一个字符串。然后先把words生成对应的整数，然后两两比较是否会出现两个整数&==0,这样表示没有字母重复

class Solution {
public:
    int maxProduct(vector<string>& words) {

        int nums[words.size()];
        memset(nums,0,sizeof(nums));
        
        
        for(int i = 0; i < words.size(); ++i) {
            for(char c :words[i]) {
                nums[i]|=1<<(c-'a');
            }
        }
        int res = 0;
        
        for(int i = 0; i < int(words.size())-1; ++i) {
            for(int j = 1; j < words.size(); ++j) {
                if(!(nums[i]&nums[j])) res = max(res,int(words[i].size())*int(words[j].size()));
            }
        }
        
        return res;
        
    }
};