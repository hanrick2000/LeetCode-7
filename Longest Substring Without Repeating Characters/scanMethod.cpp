//此方法用指针p线性扫描一边  用hash记录每一个字符即出线的index，然后遇到重复的，p回退到重复位置，然后继续扫描，当p扫倒和末尾差距小于当前最大值就可以剪枝。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int dic[128]={0};
        
        int max = 0;
        int cur = 0;
        
        for(int i = 0; i < s.size(); ++i) {
            
            if(!dic[s[i]]) {
                cur++;
                dic[s[i]] = i+1;
            }
            else {
                max = max>cur?max:cur;
                cur = 0;
                i = dic[s[i]]-1;
                fill_n(dic, 128, 0);
                if(s.size()-1<=max+i) break;
            }
        }
        
        max = max>cur?max:cur;
        return max;
        
    }

};