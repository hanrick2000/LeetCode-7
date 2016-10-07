//Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
//
//Example 1:
//Given words = ["bat", "tab", "cat"]
//Return [[0, 1], [1, 0]]
//The palindromes are ["battab", "tabbat"]
//Example 2:
//Given words = ["abcd", "dcba", "lls", "s", "sssll"]
//Return [[0, 1], [1, 0], [3, 2], [2, 4]]
//The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

//O(k * n ^2)解法其中k为单词个数，n为单词的长度：
//利用字典wmap保存单词 -> 下标的键值对
//
//遍历单词列表words，记当前单词为word，下标为idx：
//
//1). 若当前单词word本身为回文，且words中存在空串，则将空串下标bidx与idx加入答案
//
//2). 若当前单词的逆序串在words中，则将逆序串下标ridx与idx加入答案
//
//3). 将当前单词word拆分为左右两半left，right。
//
//     3.1) 若left为回文，并且right的逆序串在words中，则将right的逆序串下标rridx与idx加入答案
//     
//     3.2) 若right为回文，并且left的逆序串在words中，则将left的逆序串下标idx与rlidx加入答案


class Solution {
public:

    string rev(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return s1;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        unordered_map<string,int> mymap;
        
        for(int i = 0; i < words.size(); ++i)  {
            mymap[words[i]] = i;
        }
        
        vector<vector<int>> res;
        for(int i = 0; i < words.size(); ++i) {
            
            string s1 = words[i];
            reverse(s1.begin(), s1.end());
            
            if(s1 == words[i] && mymap.find("")!=mymap.end() && s1!="") {
                res.push_back({i, mymap[""]});
                res.push_back({mymap[""], i});
            }
            
            if(mymap.find(s1)!=mymap.end() && s1!=words[i]) res.push_back({i, mymap[s1]});
            
            for(int j = 1; j < words[i].size(); ++j) {
                string p = words[i].substr(j);
                string p2 = words[i].substr(0,j);
                string r = rev(p);
                string r2 = rev(p2);
                if(p2 == r2 && mymap.find(r)!=mymap.end()) res.push_back({mymap[r], i});
                if(p == r && mymap.find(r2)!=mymap.end()) res.push_back({i, mymap[r2]});
            }
            
        }
        
        return res;
    }
};