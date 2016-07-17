////Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//
//click to show follow up.
//
//Follow up:
//Did you use extra space?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution?



// 这题果断不能傻逼的开辟一个m*n数组，得利用原始数组的位置纪录. 用第一行第一列进行纪录，把[i][j]为零的元素， [0][i] [j][0]再置为0.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool flag1, flag2;
        
        for(int i = 0; i < matrix.size(); ++i) {
            if(!matrix[i][0]) {
                flag1 = true;
                break;
            }
        }
        
        for(int i = 0; i < matrix[0].size(); ++i) {
            if(!matrix[0][i]) {
                flag2 = true;
                break;
            }
        }
        
        for(int i = 1; i < matrix.size(); ++i) {
            for(int j = 1 ; j < matrix[0].size(); ++j) {
                if(!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = 1; i < matrix.size(); ++i) {
            if(!matrix[i][0]) {
                for(int j = 1 ; j < matrix[0].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int j = 1; j < matrix[0].size();++j) {
            if(!matrix[0][j]) {
                for(int i = 1; i < matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(flag2) {
            for(int i = 0; i < matrix[0].size(); ++i) {
                matrix[0][i] = 0;
            }
        }
        
        if(flag1) {
            for(int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }        
    }
};