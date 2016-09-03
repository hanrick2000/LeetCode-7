//Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
//
//For example, Given s = “eceba”,
//
//T is "ece" which its length is 3.

//这题是典型的一前一后两指针做法，前指针i是在扫描字符串s,后指针p是记录当前的仅拥有至多两个不同字符的字符串的起始位置。用一个hashmap 记录当前子串所拥有的字符及个数。用len记录当前已有几个不同字符了。 每一次移动i有三种可能
//i) 当前字符，在子串中。无论怎么样允许加入，更新maxi,再更新hashmap,不用更新len
//ii) 当前字符不在子串中，且当前少于两个不同字符。那么更新hashmap,更新len,更新maxi.
//iii) 当前字符不在字串中，而且当前子串已有两个不同字符。那么循环前进p,把之前的字符踢掉，每踢掉一个字符，更新hashmap,直到发现某一个字符的次数变为0了，说明少了一个字符，加上现在i所指向的字符，正好两个字符，所以，len还是2不用更新，该字符的hashmap还是要更新。时间O(2n) = O(n)

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int p = 0, len = 0, maxi = 0, a[128];
        memset(a,0,sizeof(a));

        for(int i = 0; i < s.size(); ++i) {
            
            if(a[s[i]]) {
                maxi = max(i - p + 1, maxi); 
            }
            
            else {
                if(len<2) {
                    maxi = max(i - p + 1, maxi); 
                }
                
                else {
                    while(1) {
                        if(!--a[s[p++]]) {
                            --len;
                            break;
                        }
                    }
                }
                ++len;
            }
            ++a[s[i]];
        }
        
        return maxi;
    }
};