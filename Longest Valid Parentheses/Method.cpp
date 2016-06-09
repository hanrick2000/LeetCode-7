//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

//我们可以用动态规划算法。
//比如有如下例子：")()())"
//我们初始化 一个 start指针变量 和 变量pre,表示当前字符距离start位置之间多了多少个'('，  我们可以对string 进行扫描，如果当前字符是'(' ++pre,否则 --, 如果pre == 0 则表明 start 到 i之间是well-formed的，可以更新max。如果pre<0,表明')'多一个. ')'多一个是不可能在start 到i之间有well-formed的。所以start应该更新到i。
//但只从这边还不能应付这种例子  "(()",想象一下我们可以把整个string 反转 进行上述过程 就可以，因此我们可以从右边再执行类似过程。

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int max = 0, pre = 0,start = -1;
        
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                ++pre;
            }
            else if(!pre) {
                start = i;
            }
            else {
                if(!--pre) max = max < i-start? i-start:max; 
            }
        }
        pre = 0, start = s.size();
        
        for(int i = s.size()-1; i >=0; --i) {
            if(s[i] == ')') {
                ++pre;
            }
            else if(!pre) {
                start = i;
            }
            else {
                if(!--pre) max = max < start - i? start - i:max; 
            }
        }
        
        return max;
    }
};