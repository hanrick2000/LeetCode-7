//You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
//For example, given:
//s: "barfoothefoobarman"
//words: ["foo", "bar"]
//
//You should return the indices: [0,9].
//(order does not matter).

//这题这个思路和longest substring without repitition一样。只不过这回得用map做数据结构。外循环i从0开始，i++，然后里面循环j从i开始,依次，几个几个字符拿出来 和 words里面比较。
//时间复杂度o(n*n/L) 
//空间O(m) m为不同单词的个数

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        
        unordered_map<string,int> mymap;
        int L = words[0].size();
        int totalL = words.size()*L;
        
        for(auto &x: words) {
            mymap[x]++;
        }
        
        for(int i = 0; i + totalL <= s.size(); ++i) {
            unordered_map<string,int> tempmap;
            int j = i;
            for(; j < i+totalL; j+=L) {         //只需判断从i开始的totall个字符即可
                string temp = s.substr(j,L);
                // tempmap[temp]++;
                if(mymap.find(temp) == mymap.end()) break;  
                if(++tempmap[temp]>mymap[temp]) break;
            }
            //字符一样长，每一次循环也不触发上两个break，可以推断这两个map是一样的。
            if(j == i+totalL) result.push_back(i);  //判断究竟是break出来的还是自然循环结束的
        }
        
        return result;
        
    }
};