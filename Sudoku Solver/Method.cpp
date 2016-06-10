//Write a program to solve a Sudoku puzzle by filling the empty cells.
//
//Empty cells are indicated by the character '.'.
//
//You may assume that there will be only one unique solution.
//
//
//A sudoku puzzle...
//
//
//...and its solution numbers marked in red.


//数独就是每行  每列 和每一个3*3子方块里面都得是1到9的排列，不饿能重复。
//显然用dfs搜索, 递归出口很简单，就是所有的方块都填上数字了。
//但是填数字是有限制的。满足不了限制就得回溯。
//限制可以用几组hash map去搞定，对于每一行，用一个 数组去记录每一个数字出现与否，每一列也一样，每一个小方块也一样，所以一共需要27个9维向量去记录。

class Solution {
    bool horimap[9][9];
    bool vertimap[9][9];
    bool chunkmap[9][9]; 
public:

    bool hasNext(vector<vector<char>>& board, int &i, int &j) {
        for(int k = i*9+j; k < 81; ++k) {  //查找下一个未填的数
            i = k/9;
            j = k%9;
            if(board[i][j] == '.') return true;
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j) {
        if(!hasNext(board,i,j)) {  //没有未填  就为递归出口。  否则i,j指向待填位置。
            return true;
        } 
        
        for(int k = 0; k < 9; ++k) {    //  
            int m = (i/3)*3+j/3;
            if(!horimap[i][k]&&!vertimap[j][k]&&!chunkmap[m][k]) {  //对满足限制的数字进行搜索
                board[i][j] = k+1+'0'; //修改棋盘
                
                horimap[i][k] = vertimap[j][k] = chunkmap[m][k] = true; //修改hash表
                if(dfs(board, i,j)) return true;
                board[i][j] = '.';  //回溯  还原棋盘
                horimap[i][k] = vertimap[j][k] = chunkmap[m][k] = false;  //回溯 还原hash表
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; ++i) {  //每行
            for(int j = 0; j < 9; ++j) {
                if(board[i][j]!='.') {
                    horimap[i][board[i][j]-'1'] = true; 
                }
            }
        }
        
        for(int i = 0; i < 9; ++i) {  //每列
            for(int j = 0; j < 9; ++j) {
                if(board[j][i]!='.') {
                    vertimap[i][board[j][i]-'1'] = true; 
                }
            }
        }

        for(int i = 0; i < 9; ++i) {   //记录小方块里的出现的🌲
            for(int j = 0; j < 9; ++j) {
                if(board[(i/3)*3+j/3][i%3*3+j%3]!='.') {
                    chunkmap[i][board[(i/3)*3+j/3][i%3*3+j%3]-'1'] = true;
                }
            }
        }

        dfs(board,0,0);
        
    }
};