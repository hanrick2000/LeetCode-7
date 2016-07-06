//Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
//
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
//
//Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//
//For the last line of text, it should be left justified and no extra space is inserted between words.
//
//For example,
//words: ["This", "is", "an", "example", "of", "text", "justification."]
//L: 16.
//
//Return the formatted lines as:
//[
//   "This    is    an",
//   "example  of text",
//   "justification.  "
//]
//Note: Each word is guaranteed not to exceed L in length.
//
//click to show corner cases.
//
//Corner Cases:
//A line other than the last line might contain only one word. What should you do in this case?
//In this case, that line should be left-justified.

//这道题思路还是比较清晰的，遍历words, 每一次记录一个line 变量 来保证每一行我们可以放下最多的words, 确定某一行words之后，我们得填充空格，空格是尽量平均分配在n-1个空隙中，所以少的就是空格数量/n-1, 前面 空格数量%n-1个空隙再多一个空格。
//循环结束后，最后一个不要忘了添加。

class Solution {
public:
    
    string process(vector<string>& wordsLine,int maxWidth) {
        if(!wordsLine.size()) return "";
        
        int len = 0;
        string res;
        
        if(wordsLine.size()==1) {
            res = wordsLine[0];
            while(res.size() < maxWidth) res+= " ";
            return res;
        }
            
        for(auto &x: wordsLine) {
            len+=x.size();
        }

        int ave = (maxWidth-len)/(wordsLine.size()-1);
        
        int l = (maxWidth-len)%(wordsLine.size()-1);
        
        for(int i = 0; i < wordsLine.size()-1; ++i) {
            string space(ave,' ');
            if(i < l) space += " ";
            res += wordsLine[i] + space;

        }
        res += wordsLine.back();

        return res;
        
    }
    
    
    string process_end(vector<string>& wordsLine,int maxWidth) {
        
        int first = 0;
        string line;
        
        for(auto &x: wordsLine) {
            line += first? " "+x: x;
            first = 1;
        }
        
        while(line.size() < maxWidth) line+=" ";

        return line;
    }
    

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int first = 0, cur = 0;
        
        vector<string> wordsLine;
        vector<string> res;
        
        for(int i = 0; i < words.size(); ++i) {
            if(cur + first + words[i].size() <= maxWidth) {
                cur += first + words[i].size();
                wordsLine.push_back(words[i]);
                first = 1;
            }
            
            else {
                cur = first = 0;
                res.push_back(process(wordsLine, maxWidth)); //肯定不是最后一行
                --i;
                wordsLine.clear();
            }
        }
        
        res.push_back(process_end(wordsLine, maxWidth));
        
        return res;
        
    }
};