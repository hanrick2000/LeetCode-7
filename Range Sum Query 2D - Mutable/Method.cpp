//Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
//
//Range Sum Query 2D
//The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
//
//Example:
//Given matrix = [
//  [3, 0, 1, 4, 2],
//  [5, 6, 3, 2, 1],
//  [1, 2, 0, 1, 5],
//  [4, 1, 0, 1, 7],
//  [1, 0, 3, 0, 5]
//]
//
//sumRegion(2, 1, 4, 3) -> 8
//update(3, 2, 2)
//sumRegion(2, 1, 4, 3) -> 10
//Note:
//The matrix is only modifiable by the update function.
//You may assume the number of calls to update and sumRegion function is distributed evenly.
//You may assume that row1 ≤ row2 and col1 ≤ col2.

//用二维BIT ,注意二维BIT本质上只是一个二维数组。所以可以关注一下它的写法，其实就多了一层循环而已。

class BIT{
    
    int height;
    int width;
    vector<vector<int>> array;
    vector<vector<int>> arr;
    
    inline int lowBit(int index) {
        return index&(-index);
    }
    
public:
    BIT(vector<vector<int>> &matrix)  {
        
        
        height = matrix.size();
        if(height == 0) return;
        width = matrix[0].size();
        
        array = vector<vector<int>> (height+1, vector<int> (width+1));
        arr = matrix;
        
    }
    
    int sum(int index1, int index2) {
        int s = 0;
        for(int i = index1; i ; i -= lowBit(i)){
            for(int j = index2; j ; j -= lowBit(j)){
                s += array[i][j];
            }
        }
        return s;
    }
    
    void add(int index1, int index2, int delta) {
        
        for(int i = index1; i <= height; i += lowBit(i)){
            for(int j = index2; j <= width; j += lowBit(j)){
                array[i][j]+= delta;
            }
        }
    }
    
    
    void set(int index1, int index2, int val) {
        
        add(index1, index2, val - arr[index1-1][index2-1]);
        arr[index1-1][index2-1] = val;
    }
};


class NumMatrix {
    BIT tree;
public:
    NumMatrix(vector<vector<int>> &matrix): tree(matrix) {

        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                tree.add(i+1,j+1,matrix[i][j]);
            }
        }
        
    }
    
    void update(int row, int col, int val) {
        tree.set(row+1, col+1, val);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        return tree.sum(row2+1, col2+1) - tree.sum(row1, col2+1) - tree.sum(row2+1, col1) + tree.sum(row1, col1);
    }
};
// [[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]],sumRegion(2,1,4,3),update(3,2,2,sumRegion(2,1,4,3)

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);