//Given a string, find the length of the longest substring T that contains at most k distinct characters.
//
//For example, Given s = “eceba” and k = 2,
//
//T is "ece" which its length is 3.


//这题慢慢的也要背出来了，用一个p指针指向满足条件的string开始的前一个位置，然后不断移动i指针
    
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        int p = -1, maxi = 0;
        vector<int> visisted(128);
        
        for(int i = 0; i < s.size(); ++i) {
            if(visisted[s[i]]++) {   //如果已经出现过这个字符，不管K。更新max
                maxi = max(i-p, maxi);
            }
            else {
                if(k) {  // 如果k还有余额，  减k,更新max
                    --k;
                    maxi = max(i-p, maxi);
                }
                
                else {   //k没余额了，p指针得前移，直到某一个字符被出现次数弄为0
                    while(--visisted[s[++p]]) ;
                }
            }
        }
        
        return maxi;
    }
    
    最简洁。。
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int p = -1, res = 0;
        vector<int> mymap(128,0);
        for(int i = 0; i < s.size(); ++i) {
            if(mymap[s[i]]++ || k--) {
                res = max(res, i-p);
            } else {
                
                while(--mymap[s[++p]]) ;
                ++k;
            }
        }
        return res;
        
    }
};
