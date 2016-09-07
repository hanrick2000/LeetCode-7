//This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
//
//Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//
//word1 and word2 may be the same and they represent two individual words in the list.
//
//For example,
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
//Given word1 = “makes”, word2 = “coding”, return 1.
//Given word1 = "makes", word2 = "makes", return 3.
//
//Note:
//You may assume word1 and word2 are both in the list.

//很简单的一个做法，在I的基础上判断一下两个Word到底想不想等。相等就可以直接查找这个词，记录距离。做法一样

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if(word1 == word2) {
            int w1 = -1,mini = words.size();
            for(int i = 0; i < words.size(); ++i) {
                if(words[i] == word1) {
                    if(w1>=0) {
                        mini = min(mini, i - w1);
                    }
                    w1 = i;
                }
                
                
            }
            return mini;
        }
        
        
        int w1 = -1, w2 = -1, mini = words.size();
        for(int i = 0; i < words.size(); ++i) {
            if(words[i] == word1) {
                w1 = i;
                if(w2>=0) {
                    mini = min(mini, w1-w2);
                }
            }
            
            if(words[i] == word2) {
                w2 = i;
                if(w1>=0) {
                    mini = min(mini, w2-w1);
                }                
            }
            
        }
        
        return mini;
        
        
        
    }
};