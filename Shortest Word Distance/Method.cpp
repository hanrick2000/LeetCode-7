//Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//
//For example,
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
//Given word1 = “coding”, word2 = “practice”, return 3.
//Given word1 = "makes", word2 = "coding", return 1.
//
//Note:
//You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.


//线性扫描，每一次如果遇到word1, 减去上一个word2出现的位置，如果遇到word2,减去上一个word1出现的位置。在这些位置里面求最小

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
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