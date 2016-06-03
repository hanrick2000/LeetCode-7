//Write a function to find the longest common prefix string amongst an array of strings.
//注意[],[""]这种边界条件


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        if(strs.size()==1) return strs[0];
        string res;
        int k = 0;
        
        while(1) {
            
            for(int i = 0; i < strs.size()-1; ++i) {
                if(k == strs[i].size()||strs[i][k]!=strs[i+1][k]) return res;
            }
            res += strs[0][k];
            k++;
        }
        
        return res;        
        
    }
};