//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//For example,
//S = "ADOBECODEBANC"
//T = "ABC"
//Minimum window is "BANC".
//
//Note:
//If there is no such window in S that covers all characters in T, return the empty string "".
//
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.


//用双指针 + map的做法，首先map得记录t中各个字符出现了几次。然后，保持一个前进i指针和一个尾指针p。p指向当前字符串的前面一个位置(初始化-1). 然后线性扫描，没遇到一个t里面的字符就--相应的hashmap, 直到hashmap所有字符都<=0才算有一个子串，然后可以动p指针，把那些可以舍弃的字符全部抛掉。记录最短子串。然后++p指针，继续。

class Solution {
public:

    
    string minWindow(string s, string t) {
        
        unordered_map<char, int> counts;
        
        for(auto x: t) {
            ++counts[x];
        }

        int p = -1, i = 0, mini = s.size()+1, len = counts.size();
        string rst;
        
        for(; i < s.size(); ++i) {
            if(counts.find(s[i])!=counts.end())  {
                
                --counts[s[i]];
                if(!counts[s[i]]) --len;
                if(!len) {

                    while(1) {

                        if(counts.find(s[p+1]) == counts.end()) ++p;
                        
                        else if(counts[s[p+1]] < 0) {
                            
                            ++p;
                            ++counts[s[p]];
                        }
                        else {
                            break;
                        }      
                    }
         
                    if(i-p < mini) {
                        mini = i-p;
                        rst = s.substr(p+1, i-p);
                    }

                    ++p;
                    ++counts[s[p]];
                    if(counts[s[p]]) ++len;
                }
                
            }
            
        }
        
        return rst;
        
        
    }
};
    简介的多的版本， 只要用m来记录t字符中的出现次数，m2来作为备份， k记录t有多少个不同的字符.
    string minWindow(string s, string t) {
        int m[128] = {0}, m2[128]={0};
        
        string res;
        int p = -1, k = 0, sz = s.size()+1;
        
        for(auto &c: t) {
            if(++m[c]==1) {
                ++k;
            } 
            ++m2[c];
        }

        for(int i = 0; i < s.size(); ++i) {
            
            if(m2[s[i]] && --m[s[i]] == 0) --k;   //其中一个字符已经全部包含
            
            if(k == 0) {   //全部字符都已包含，
                while(!(m2[s[p+1]]) || m[s[p+1]]+1<=0) {   //看看能不能从头部去掉一下多余的字符。不出现在t中的和t中多余的都可以去
                    ++p;
                    if(m2[s[p]]) ++m[s[p]];  //如果去的是t中多余的，修改相应的hash
                }
                if(i - p < sz) {    //更新
                    res = s.substr(p+1, i-p);
                    sz = i - p;
                }
            }
        }
        return res;
    }
