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