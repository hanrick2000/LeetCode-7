//The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
//Given an integer n, return all distinct solutions to the n-queens puzzle.
//
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//For example,
//There exist two distinct solutions to the 4-queens puzzle:
//
//[
// [".Q..",  // Solution 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // Solution 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]

//显然用dfs，深度代表棋盘的行下标，  每一次深搜都考虑所有位置（该行的所有列），用一个hash表记录深搜到目前之前的所有被Queen占用的列，来加快速度。最后是否继续深搜 需要满足queen斜线也不存在，所以用绝对值之差即可 本思路先产生每一行q所在的列数下标，然后转化成结果。

class Solution {
public:
    
    bool valid(vector<int> &cur, int depth, int i) {  //depth ，i记录了当前的皇后位置
        for(int j = 0; j < depth; ++j) {
            if(depth-j == abs(i-cur[j])) return false;
        }
        
        return true;
    }
    
    void dfs(int depth, vector<int> &cur, vector<vector<string>> &res, int n, vector<bool> &ocupied) {
        if(depth == n) {
            vector<string> cur2(n,string(n,'.'));  
            for(int i = 0; i < cur.size(); ++i) { //转化结果
                cur2[i][cur[i]] = 'Q';
            }
             
            res.push_back(cur2);
            return;
        }
        
        for(int i = 0; i < n; ++i) { //每一列
            if(ocupied[i]) continue;  //该列已有之前的Queen占领
            if(valid(cur, depth, i)) {
                cur[depth] = i;
                ocupied[i] = true;
                dfs(depth+1,cur,res,n,ocupied);
                ocupied[i] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        // vector<vector<int>> res;
        vector<int> cur(n,-1);
        vector<bool> ocupied(n,false);
                
        vector<vector<string>> res;
        
        dfs(0,cur,res,n,ocupied);
        
        return res;
    }
};