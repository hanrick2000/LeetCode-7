//Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
//
//For example:
//
//Given "aacecaaa", return "aaacecaaa".
//
//Given "abcd", return "dcbabcd".

//这题思想就是找到S开头的最长回文，然后把剩下的那一部分逆序的拼到S前面就是答案，如何快速求出这个最长回文呢？如果用普通方法肯定要O（n2)时间。这里 用了传说中的KMP算法里面的next数组。next数组记录的是字符串从头到当前字符这一子串的最长公共前后缀的长度。所以我们将S + ‘#’ + S_rev 拼起来，求它的最长公共前后缀就是S开头的最长回文串。

class Solution {
public:

    int makeNext(string &s) {
        
        if(s == "") return 0;
        
        int q,k;//q:模版字符串下标；k:最大前后缀长度
        int m = s.size();//模版字符串长度

        vector<int> next(s.size());
        next[0] = 0; //模版字符串的第一个字符的最大前后缀长度为0
        for (q = 1,k = 0; q < m; ++q) { //for循环，从第二个字符开始，依次计算每一个字符对应的next值 
            while(k > 0 && s[q] != s[k]) //递归的求出P[0]···P[q]的最大的相同的前后缀长度k
                k = next[k-1];          //不理解没关系看下面的分析，这个while循环是整段代码的精髓所在，确实不好理解  
            if (s[q] == s[k]) {//如果相等，那么最大相同前后缀长度加1
                k++;
            }
            next[q] = k;
        }
        return next.back();
    }


    string shortestPalindrome(string s) {
        
        string s1 = s;
        reverse(s1.begin(), s1.end());
        
        string s2 = s + "&" + s1;
        int next = makeNext(s2);

        return  s1.substr(0,s.size()-next) + s;
        
    }
};