//According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
//
//Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
//
//Any live cell with fewer than two live neighbors dies, as if caused by under-population.
//Any live cell with two or three live neighbors lives on to the next generation.
//Any live cell with more than three live neighbors dies, as if by over-population..
//Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//Write a function to compute the next state (after one update) of the board given its current state.
//
//Follow up: 
//Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
//In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?


//思想很简单，关键是如何inplace。我们可以用3表示  原来是1，下一轮变为0， 用2表示原来是0下一轮变为1.最后棋盘的每一个子刷新后在把3,2复原。


class Solution {
public:

    int getBoard(vector<vector<int>>& board, int i, int j) {
        if(i < 0|| i >= board.size() || j <0 || j >= board[0].size()) return 0;
        
        return board[i][j];
        
    }
    
    // int evaluate()

    void gameOfLife(vector<vector<int>>& board) {
        
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                int num = 0;
                
                if(getBoard(board,i-1,j-1)==1||getBoard(board,i-1,j-1)==3) ++num;
                if(getBoard(board,i-1,j)==1||getBoard(board,i-1,j)==3) ++num;
                if(getBoard(board,i-1,j+1)==1||getBoard(board,i-1,j+1)==3) ++num;
                if(getBoard(board,i,j-1)==1||getBoard(board,i,j-1)==3) ++num;
                
                if(getBoard(board,i,j+1)==1||getBoard(board,i,j+1)==3) ++num;
                if(getBoard(board,i+1,j-1)==1||getBoard(board,i+1,j-1)==3) ++num;
                if(getBoard(board,i+1,j)==1||getBoard(board,i+1,j)==3) ++num;
                if(getBoard(board,i+1,j+1)==1||getBoard(board,i+1,j+1)==3) ++num;
                
                if(board[i][j] == 1) {
                    if(num < 2 || num > 3) board[i][j] = 3;
                }
                
                else {
                    if(num == 3) board[i][j] = 2;
                }
            }
        }
        
        
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == 3) board[i][j] = 0;
                
            }
        }
        
        
        
    }
};