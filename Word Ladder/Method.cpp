//Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//Only one letter can be changed at a time
//Each intermediate word must exist in the word list
//For example,
//
//Given:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//return its length 5.
//
//Note:
//Return 0 if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.


//图的搜索bfs。 但是到底怎么快速找到所有哪些与本单词只有一字符之差的单词呢？可以将本单词每一个字符进行替换，看看是否在set中。最后bfs中对已经入队列的，就可以在set中删除了。


class Solution {
public:
    

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    
        wordList.insert(beginWord);
        wordList.insert(endWord);

        queue<string> myque;
        
        myque.push(beginWord);
        int level = 0;
        
        while(myque.size()) {
            ++level;
            int len = myque.size();
            
            for(int i = 0; i < len; ++i) {
                string tmp = myque.front();
                myque.pop();
                if(tmp == endWord) return level;
                
                for(int i = 0; i < tmp.size(); ++i) {
                    string tmp2 = tmp;
                    for(char c = 'a'; c <='z'; ++c) {
                        if (c==tmp[i]) continue;
                        tmp2[i] = c;
                        if(wordList.find(tmp2)!=wordList.end()) {
                            wordList.erase(tmp2);
                            myque.push(tmp2);
                        }
                    }
                    
                }
            
            }
            
        }
        
        
        return 0;
    }


};