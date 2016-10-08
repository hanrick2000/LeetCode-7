//Implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch("aa","a") → false
//isMatch("aa","aa") → true
//isMatch("aaa","aa") → false
//isMatch("aa", "*") → true
//isMatch("aa", "a*") → true
//isMatch("ab", "?*") → true
//isMatch("aab", "c*a*b") → false

//这题如果用递归+memo会超时，原因在于即便使用了带记录的递归，对于p上的每一个'*'，依然需要考虑'*' 匹配之后字符的所有情况，比如p = "c*ab*c"，s = "cddabbac"时，遇到第一个'*'，我们需要用递归处理p的剩余部分"ab*c" 和s的剩余部分"ddabbac"的所有尾部子集匹配。也就是："ab*c"和"ddabbac"，"ab*c" 和"dabbac"的匹配，"ab*c" 和"abbac"的匹配，... ，"ab*c" 和"c"的匹配，"ab*c" 和"\0"的匹配。
//
//遇到第二个'*'，依然如此。每一个'*'都意味着p的剩余部分要和s的剩余部分的所有尾子集匹配一遍。
//
//然而，我们如果仔细想想，实际上，当p中'*'的数量大于1个时，我们并不需要像上面一样匹配所有尾子集。
//
//依然以 p = "c*ab*c"，s = "cddabbac"为例。
//
//对于p = "c*ab*c"，我们可以猜想出它可以匹配的s应该长成这样： "c....ab.....c"，省略号表示0到任意多的字符。我们发现主要就是p的中间那个"ab"比较麻烦，一定要s中的'ab'来匹配，因此只要s中间存在一个"ab"，那么一切都可以交给后面的'*'了。
//
//所以说，当我们挨个比较p和s上的字符时，当我们遇到p的第一个'*'，我们实际只需要不断地在s的剩余部分找和'ab'匹配的部分。
//
//换言之，我们可以记录下遇到*时p和s的位置，记为presp和press，然后挨个继续比较*(++p)和*(++s)；如果发现*p != *s，就回溯回去，p = presp，s = press+1, ++press；直到比较到末尾，或者遇到了下一个'*'，如果遇到了下一个'*'，说明 "ab"部分搞定了，下面的就交给第二个'*'了；如果p和s都到末尾了，那么就返回true；如果到末尾了既没遇到新的'*'，又还存在不匹配的值，press也已经到末尾了，那么就返回false了。
//
//这样的思路和上面的递归比起来，最大的区别就在于：
//
//遇到'*'，我们只考虑遇到下一个'*'前的子问题，而不是考虑一直到末尾的子问题。从而避免大量的子问题计算。
//
//我们通过记录 presp和press，每次回溯的方法，避免使用递归。

//所以这题正确的方法就是使用贪心法。复杂度O(mn).

class Solution {
public:
    bool isMatch(string s, string p) {
 
        int i = 0, j = 0, lastp = -1, lasts = -1;
        
        while(i < s.size()) {

            if(j < p.size() && (s[i] == p[j] || p[j] == '?')) {
                ++i;++j;
            }
            
            else if(j < p.size()&& p[j] == '*') {  //每次遇到*做好回溯的准备
                lasts = i;
                lastp = ++j;   //p要循环从这里开始
            }
            
            else {
                if(lastp == -1) return false;

                i = ++lasts;   //lasts 记录了上次匹配回溯时(*后面的那个p[j]匹配的是s[lasts],所以++lasts. 
                j = lastp;  //回溯说明这个*还没匹配到正确结果
            }
        }
                    
        while(j < p.size() && p[j] == '*') ++j;
            
        return j == p.size();
    }

};


