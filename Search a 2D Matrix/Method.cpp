//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//For example,
//
//Consider the following matrix:
//
//[
//  [1,   3,  5,  7],
//  [10, 11, 16, 20],
//  [23, 30, 34, 50]
//]
//Given target = 3, return true.


//二分查找的运用 

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int a = 0, b = matrix.size()*matrix[0].size()-1,c,row,col;
        
        while(a <= b) {
            c = (a+b)/2;
            
            row = c/matrix[0].size();
            col = c%matrix[0].size();
            
            if(matrix[row][col] < target) {
                a = c+1;
            }
            
            else if (matrix[row][col] > target) {
                b = c-1;
            }
            
            else {
                return true;
            }
        }
        
        return false;
        
    }
};

又被洗脑了，，，这题还是先按列二分查询，然后按行二分查询。这样复杂度也是log(m) + log(n) == log(mn).而且不会有乘法溢出，除法和模之类的耗时操作。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int p = 0, q = matrix.size()-1;
        
        while(p<q) {
            int c = (p+q+1)/2;
            if(matrix[c][0] == target) return true;
            if(matrix[c][0] > target) q = c-1;
            else p = c;
        }
        
        if(matrix[p][0] > target) return false;
        
        int p2 = 0;
        q = matrix[p].size()-1;
        
        while(p2<=q) {
            int c = (p2+q)/2;
            if(matrix[p][c] == target) return true;
            if(matrix[p][c] > target) q = c-1;
            else p2 = c+1;
        }
        
        return false;
    }
};