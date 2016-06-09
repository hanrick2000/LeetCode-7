//Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//
//A partially filled sudoku which is valid.
//
//Note:
//A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

//没啥好说  考察循环不扎实

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i) {
            bool a[9] = {0};
            for(int j = 0; j < 9; ++j) {
                if(board[i][j]!='.') {
                    if(a[board[i][j]-'1']) return false;
                    a[board[i][j]-'1'] = true;
                }
            }
        }

        for(int i = 0; i < 9; ++i) {
            bool a[9] = {0};
            for(int j = 0; j < 9; ++j) {
                if(board[j][i]!='.') {
                    if(a[board[j][i]-'1']) return false;
                    a[board[j][i]-'1'] = true;
                }
            }
        }

        for(int i = 0; i < 9; ++i) {
            bool a[9] = {0};
            for(int j = 0; j < 9; ++j) {
                if(board[(i/3)*3+j/3][i%3*3+j%3]!='.') {
                    if(a[board[(i/3)*3+j/3][i%3*3+j%3]-'1']) return false;
                    a[board[(i/3)*3+j/3][i%3*3+j%3]-'1'] = true;
                }
            }
        }
        return true;
    }
};