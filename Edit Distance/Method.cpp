//Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
//
//You have the following 3 operations permitted on a word:
//
//a) Insert a character
//b) Delete a character
//c) Replace a character

很简单的动态规划。  设opt[i][j]表示 word1[0:i+1] 和 word2 [0:j+1]之间的最小编辑距离。+1完全是因为考虑到word1和word2是空串的情形。 递归公式 opt[p][q] = 1+opt[p-1][q-1] {当word[p-1][q-1]},  opt[p][q] = 1+min(opt[p-1][q] ,opt[p-1][q-1] , opt[p][q-1]).  

class Solution {
public:
    
    int minDistanceHelper(string& word1, string& word2, int p, int q, vector<vector<int>>& opt) {
        if(opt[p][q]!=-1) return opt[p][q];
        
        if(!p) {
            opt[p][q] = q;
            return q;
        }
        
        if(!q) {
            opt[p][q] = p;
            return p;
        }
        
        if(word1[p-1] == word2[q-1]) {
            opt[p][q] = minDistanceHelper(word1, word2, p-1,q-1,opt);
            return opt[p][q];
        }
        
        opt[p][q] = 1+ min(min(minDistanceHelper(word1, word2, p-1, q, opt),minDistanceHelper(word1, word2, p, q-1, opt)),minDistanceHelper(word1, word2, p-1, q-1, opt));
        
        return opt[p][q];
        
    }

    int minDistance(string &word1, string &word2) {
        
        vector<int> unit(word2.size()+1,-1);
        vector<vector<int>> opt(word1.size()+1,unit);
        
        return minDistanceHelper(word1,word2, word1.size(), word2.size(), opt);
        
    }
};