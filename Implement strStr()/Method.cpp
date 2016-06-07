//Implement strStr().

//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


//我们可以用线性扫描的方式，拿needle 去去和haystack进行比较，时间复杂度O(mn)。注意！当.size() - .size()时 我们一定要转换为int,因为他们默认是unsigned ， 小于零时会变成补码。

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle == "") return 0;
        
        for(int i = 0; i <= int(haystack.size()) - int(needle.size()); ++i) {
            int j = 0;
            for(; j < needle.size(); ++j) {
                if(needle[j]!=haystack[i+j]) break;
            }
            if(j == needle.size()) return i;
        }
        
        return -1;
    }
};