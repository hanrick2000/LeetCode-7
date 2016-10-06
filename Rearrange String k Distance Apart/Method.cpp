//Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.
//
//All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".
//
//Example 1:
//str = "aabbcc", k = 3
//
//Result: "abcabc"
//
//The same letters are at least distance 3 from each other.
//Example 2:
//str = "aaabc", k = 3 
//
//Answer: ""
//
//It is not possible to rearrange the string.
//Example 3:
//str = "aaadbbcc", k = 2
//
//Answer: "abacabcd"
//
//Another possible answer is: "abcabcda"
//
//The same letters are at least distance 2 from each other.

//典型的贪心法，统计每一个单词的词频，每一次按照次数最多的字符排放K个位置直到排满str.的长度（最后一次是str长度模k,取最小的就行）。如何找这k个字符呢？从堆中取不同的k个字符出来，如果堆里面不到k个不同的字符，说明不满足要求。 取出来后，填到结果字符串中，相应的次数也--，每次填完后，再把这些还剩余的字符和次数加到堆里面去。

class Solution {
public:
    
    
    string rearrangeString(string str, int k) {
        
        if(k == 0) return str;
        
        vector<int> cnt(26);
        
        for(auto x: str) {
            ++cnt[x-'a'];
        }
        
        int len = int(str.size());
        string res;
        
        priority_queue<pair<int, char>> myheap;
        
        for(int i = 0; i < 26; i++) {
            if(cnt[i]) myheap.push(make_pair(cnt[i] , 'a'+i));
            
        }
        
        while(myheap.size()) {
            
            vector<pair<int,char>> v;
            
            int l = min(k, len);
            
            for(int i = 0; i < l; ++i) {
                if(myheap.empty()) return "";
                
                auto p = myheap.top();
                myheap.pop();
                
                res += p.second;
                
                if(--p.first) v.push_back(p);
                
                --len;
            }
            
            for(auto x:v) myheap.push(x);
            
        }
        return res;
        
    }
};