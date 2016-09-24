//Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.
//
//Example 1:
//
//Input:
//s = "aaabb", k = 3
//
//Output:
//3
//
//The longest substring is "aaa", as 'a' is repeated 3 times.
//Example 2:
//
//Input:
//s = "ababbc", k = 2
//
//Output:
//5
//
//The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

先统计一下字符串里每一个字符出现的次数，如果全到了K， 就返回字符串长度，否则找到第一个次数没有到K的字符，对左右两边的string递归，O(nlog n).

class Solution {
public:
    int longestSubstringHelper(string &s, int begin, int end, int k) {
        
        if(end < begin || end - begin + 1 < k) return 0;
        
        vector<int> occur(128,0);

        for (int i = begin; i <= end; ++i) {
            ++occur[s[i]];
        }

        int maxi = 0; 
        
        for(int i = begin; i <= end; ++i) {
            if(occur[s[i]] < k) {
                return max(longestSubstringHelper(s, begin, i-1 , k) ,longestSubstringHelper(s , i + 1, end, k));
            }
        }
        
        return end - begin + 1;
    }

    int longestSubstring(string s, int k) {
    
        return longestSubstringHelper(s, 0, s.size()-1,k);
    }
};