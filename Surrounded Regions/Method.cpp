//Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//For example,
//X X X X
//X O O X
//X X O X
//X O X X
//After running your function, the board should be:
//
//X X X X
//X X X X
//X X X X
//X O X X

//很明显dfs,如果系统最大栈比较大的话，可以用递归，对整个棋盘上的每一个点，进行dfs,如果是x，则返回false，如果该点是o且在边缘，返回true，否则，递归上下左右四个点进行递归，如果都返回false，就修改改点为x返回false，否则返回true。
//但如果系统栈不大，那只好迭代式的dfs,上述思想就不行了，我们可以从边缘的几个O出发进行dfs,修改成另外一个字符'I',然后再扫描一边棋盘，把'I'变成'O','O'变成'X'.

class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        
        stack<pair<int,int>> mystack;
        mystack.push(make_pair(i,j));
        
        while(mystack.size()) {
            pair<int,int> tmp = mystack.top();
            mystack.pop();
            int i1 = tmp.first;
            int j1 = tmp.second;
            
            board[i1][j1] = 'I';
            
            if(i1&&board[i1-1][j1]=='O') {
                mystack.push(make_pair(i1-1,j1));
            }
            
            if(j1&&board[i1][j1-1]=='O') {

                mystack.push(make_pair(i1,j1-1));
            }
            
            if(i1<board.size()-1&&board[i1+1][j1]=='O') {
                mystack.push(make_pair(i1+1,j1));
            }
            
            if(j1<board[0].size()-1&&board[i1][j1+1]=='O') {
                mystack.push(make_pair(i1,j1+1));
            }
               
        }        
    }

    void solve(vector<vector<char>>& board) {
        if(!board.size()||!board[0].size()) return;
        for(int i = 0; i < board[0].size(); ++i) {
            if(board[0][i]=='O') dfs(board,0,i);
        }
        
        for(int i = 1; i < board.size(); ++i) {
            if(board[i][board[0].size()-1]=='O') dfs(board,i,board[0].size()-1);
        }
        
        for(int i = 1; i < board[0].size(); ++i) {
            if(board[board.size()-1][i]=='O') dfs(board,board.size()-1,i);
        }    
        
        for(int i = 1; i < board.size(); ++i) {
            if(board[i][0]=='O') dfs(board,i,0);
        }
        
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j]=='I') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }

        
    }
};