//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//For example,
//Given board =
//
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//word = "ABCCED", -> returns true,
//word = "SEE", -> returns true,
//word = "ABCB", -> returns false.
//Show Company Tags
//Show Tags
//Show Similar Problems

//很显然用dfs, 不过又一个问题是它不能重复走已经走过的路，那就用一个字符去标记已经走过的路咯。那什么时候要还原这个字符呢？  就是当判断这个状态点是不可能成功时，就还原它，这就是回溯的思想。


class Solution {
public:


    bool dfs(vector<vector<char>>& board, int i, int j, string &word, string &cur) {
        
        if(cur.size() == word.size()) return true;  //层数一样深
        
        
        if(i<0||i>board.size()-1||j<0||j>board[0].size()-1||board[i][j] == '\0' || board[i][j] != word[cur.size()]) {
            return false;
        }
        
        
        char c = board[i][j];  // 还原它时需要用到拷贝
        cur += c;  
        
        
        board[i][j] = '\0';
        

        if(dfs(board, i-1,j, word,cur))
            return true;
        

        if(dfs(board, i+1,j, word,cur))
            return true;
        

        if(dfs(board, i,j-1, word,cur))
            return true;
         

        if(dfs(board, i,j+1, word,cur))
            return true;
        
        board[i][j] = c;  //还原棋盘
        cur.pop_back();   //还原cur
        return false;
        
    }


    bool exist(vector<vector<char>>& board, string &word) {
        
        string cur;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(dfs(board, i,j, word,cur))
                    return true;
            }
        }
        
        return false;
    }
};