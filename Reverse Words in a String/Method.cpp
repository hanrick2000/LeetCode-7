//Given an input string, reverse the string word by word.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//
//Update (2015-02-12):
//For C programmers: Try to solve it in-place in O(1) space.
//
//click to show clarification.
//
//Clarification:
//What constitutes a word?
//A sequence of non-space characters constitutes a word.
//Could the input string contain leading or trailing spaces?
//Yes. However, your reversed string should not contain leading or trailing spaces.
//How about multiple spaces between two words?
//Reduce them to a single space in the reversed string.


//思路是先剔除所有空格，转化为标准句子形式（头尾没有空格，单词间只有一个空格），然后给每一个单词翻转，再翻转整个字符串。
//该方法就是针对问题ii的

class Solution {
public:

    void reverseWordsHelper(string &s, int start, int end) {//start 到 end 全部反转
        int p = start,q = end;
        while(p<q){
            swap(s[p++],s[q--]);
            
        }
    }

    void reverseWords(string &s) {

        bool first = false;
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i]!=' '){
                first = true;
                s[count++] = s[i];
            }
            else {
                if(first&&s[i-1] != ' ') {
                    s[count++] = s[i];
                }
            }
        }
        while(s.size()>count) {
            s.pop_back();
        }
    
        if(s.back() != ' ') s.push_back(' ');           //最后加一个空格
    
        count = 0;
        
        for(int i = 0; i < s.size(); ++i) {         //反转每一个单词
            if(s[i] == ' ') {
                reverseWordsHelper(s,count,i-1);
            }
            else if(i&&s[i-1]==' ') {
                count = i;
            }
        }
        
        s.pop_back();
        
        reverseWordsHelper(s,0,s.size()-1);  //反转整句话。
    }
};

