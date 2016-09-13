//Given two sparse matrices A and B, return the result of AB.
//
//You may assume that A's column number is equal to B's row number.
//
//Example:
//
//A = [
//  [ 1, 0, 0],
//  [-1, 0, 3]
//]
//
//B = [
//  [ 7, 0, 0 ],
//  [ 0, 0, 0 ],
//  [ 0, 0, 1 ]
//]
//
//
//     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
//AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                  | 0 0 1 |


//对A的第i行记录哪些下标有数，对B的第j行记录哪些下标有数，然后乘的时候比较这些下标有没有相等的，相等就可以有积，不相等可以通过类似于merge的方法移动指针。因为这些下标是递增的


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
        
        vector<vector<int>> m1(A.size()), m2(B[0].size());
        
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < A[0].size(); ++j) {
                if(A[i][j]) m1[i].push_back(j);
            }
        }
        
        for(int i = 0; i < B[0].size(); ++i) {
            for(int j = 0; j < B.size(); ++j) {
                if(B[j][i]) m2[i].push_back(j);
            }
        }
        
        
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < B[0].size(); ++j) {
                int p = 0, q = 0;
                while(p < m1[i].size()&&q < m2[j].size()) {
                    if(m1[i][p] == m2[j][q]) {
                        res[i][j] += A[i][m1[i][p]]*B[m2[j][q]][j];
                        ++p;
                        ++q;
                    }
                    else if(m1[i][p] < m2[j][q]) ++p;
                    else ++q;
                }
            }
        }
        
        return res;
        
        
    }
};