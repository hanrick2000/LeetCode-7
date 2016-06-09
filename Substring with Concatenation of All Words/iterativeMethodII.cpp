//此方法击败89%的提交，思路应该是最快解的思路。
//首先是先把所给的字典利用HashMap建一下，key存word，value存这个word出现的个数。

// 因为每个单词长度一样，外层循序i只许循环wordLen次，每次指针挪一次，每一次循环遍历整个字符串。
//
// 内层循环j每次遍历一个单词，把整个S字符串遍历检查。
//
// 需要在每次大循环维护一个count，看是不是达到了给的字典字符串数量，同时维护一个index，是每个符合条件的字符串的起始index，需要存到返回结果中。index和j 像是一个窗口。
//
// 为了能够检查是不是合格字符串，在这里维护一个curmap的HashMap。 curmap就是统计了窗口之间的各个单词出现次数
//
// 
//内层循环：
// 首先检查一个单词是不是在原始字典中出现，没出现的话说明这个单词肯定不符合标准，index指针指向下一个单词的起始点（j+L），计数器和curmap都要清零。
//
// 如果这个单词temp在原始字典里出现过，用更新原始字典的方法更新curDict，如果这个单词出现的次数没有超过原始字典里记录的次数，那么count++，如果超过了，就需要挪动index指针，以单词为单位循环删substr(index,L),直到把一个temp删掉才结束，  指针index动的期间还得同步curmap。
//
// 最后，如果count达到了L的length，说明找到了一个合格的字符串，那么将index存入返回结果res中，再把index挪到下一个单词处，更新curDict和count。
//时间复杂度: 外层循环l次， 内层循环 每一个单词最多被访问两次  j 和 index. 所以是n  总共O(l*n).
//空间复杂度: O(m*l) m不同单词个数，l为单词长度。

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        
        unordered_map<string,int> mymap;
        int L = words[0].size();
        
        for(auto &x: words) {
            ++mymap[x];
        }
        
        for(int i = 0; i < L; ++i) {
    
            int count =0, index = i;
            unordered_map<string,int> curmap;
            
            for(int j = i; j + L<=s.size(); j+=L) {
                string temp = s.substr(j,L);
                if(mymap.find(temp)==mymap.end()) {
                    index=j+L;
                    curmap.clear();
                    count = 0;
                }
                
                else {
                
                    if(++curmap[temp]<=mymap[temp]) ++count;
                    else {
                        while(s.substr(index,L) != temp) {
                            --curmap[s.substr(index,L)];
                            index+=L;
                            --count;
                        }
                        --curmap[s.substr(index,L)];  // s.substr(index,L) == temp 删掉他就好
                        index+=L;
                    }
                }
                
                if(count == words.size()) {
                    result.push_back(index);
                    --curmap[s.substr(index,L)];
                    index+=L;
                    --count;
                }
            }
        }
        
        return result;
    }
};