//此方法用指针i线性扫描一边，用p记录当前未重复子串开始的上一个位置，  last记录当前字符出线的上一次index，如果上一次出现的位置比p晚，说明当前字符是第一个重复的，最长字串应从上一次出现的地方开始继续找起。时间复杂度o(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int p = -1, res = 0;
        vector<int> last(128,-1);
        for(int i = 0; i < s.size(); ++i) {
            if(last[s[i]] > p) {
                p = last[s[i]];
            }
            else {
                res = max(res, i - p);
            }
            last[s[i]] = i;
        }
        return res;
    }

};