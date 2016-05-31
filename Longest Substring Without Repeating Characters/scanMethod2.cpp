//此方法用指针p线性扫描一边，用start记录当前未重复子串的开始，  dic 记录当前字符出线的上一次index，如果上一次出现的位置比start晚，说明当前字符是第一个重复的，最长字串应从上一次出现的地方开始继续找起。时间复杂度o(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // unordered_map<char, int> dic;
        
        int dic[128];
        fill_n(dic, 128, -1);
        
        int start = 0,max = 0; //当前不重复子串 起始index
        
                
        for(int i = 0; i < s.size(); ++i) {
            
            if(dic[s[i]]>=start) {
                start = dic[s[i]]+1;
            }
            
            max = max > i-start+1?max:i-start+1;
            
            dic[s[i]] = i;
            
        }
        
        return max;
    
    }

};