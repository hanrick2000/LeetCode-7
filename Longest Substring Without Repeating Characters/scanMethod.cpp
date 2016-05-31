class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // unordered_map<char, int> dic;
        
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