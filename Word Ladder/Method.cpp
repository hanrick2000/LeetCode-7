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
    
        //wordList.insert(beginWord);   这句话是不用的。
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
    

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        
        int res = 1, len = beginWord.size();
        wordList.insert(endWord);
        queue<string> myque;
        myque.push(beginWord);
        
        while(myque.size())  {
            
            int l = myque.size();
            for(int k = 0; k < l; ++k) {
                string tmp = myque.front();
                myque.pop();
                if(tmp == endWord) return res;
                
                for(int i = 0; i < len; ++i) {
                    char d = tmp[i];
                    for(char c = 'a'; c <= 'z'; ++c) {
                        if(c == d) continue;
                        tmp[i] = c;
                        if(wordList.count(tmp)) {
                            myque.push(tmp);
                            wordList.erase(tmp);
                        }
                        tmp[i] = d;
                    }
                }
            }
            ++res;
        }
        return 0;
        
    }
    
    非常拙劣的双向BFS：记住，两个BFS 搜索判断焦点是其中一个队列展开的点在另一个队列中访问到，所以两个BFS各自维护一个队列， WordList(wordList被删掉的单词可以表示哪些单词被本BFS访问过)。
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {

    int res = 1, len = beginWord.size();
    // wordList.insert(endWord);
    queue<string> myque;
    queue<string> myque2;
    myque.push(beginWord);
    myque2.push(endWord);
    unordered_set<string> wordList2 = wordList;
    wordList.insert(endWord);
    wordList2.insert(beginWord);
    
    while(myque.size()||myque2.size())  {
        int l = myque.size();
        for(int k = 0; k < l; ++k) {
            string tmp = myque.front();
            myque.pop();
            if(!wordList2.count(tmp)) return res;
            
            for(int i = 0; i < len; ++i) {
                char d = tmp[i];
                for(char c = 'a'; c <= 'z'; ++c) {
                    if(c == d) continue;
                    tmp[i] = c;
                    if(wordList.count(tmp)) {
                        myque.push(tmp);
                        wordList.erase(tmp);
                    }
                    tmp[i] = d;
                }
            }
        }
        ++res;
        int l2 = myque2.size();
        for(int k = 0; k < l2; ++k) {
            string tmp = myque2.front();
            myque2.pop();
            if(!wordList.count(tmp)) return res;
            
            for(int i = 0; i < len; ++i) {
                char d = tmp[i];
                for(char c = 'a'; c <= 'z'; ++c) {
                    if(c == d) continue;
                    tmp[i] = c;
                    if(wordList2.count(tmp)) {
                        myque2.push(tmp);
                        wordList2.erase(tmp);
                    }
                    tmp[i] = d;
                }
            }
        }
        ++res;
    }
    return 0;
    
}

};