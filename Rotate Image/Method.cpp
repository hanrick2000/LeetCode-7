//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees (clockwise).
//
//Follow up:
//Could you do this in-place?


//这题额外开辟一个方阵去做很简单，只要把第i列逆序赋值给新矩阵的第i行即可.空间O(n^2)
//in-place可以从外面一圈开始旋转，往里递进。空间O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int temp;
        
        for(int i = 0; i < matrix.size()/2; ++i) {
            for(int j = i; j < matrix.size()-i-1; ++j) {  //  size()-i-1很关键！
                //找清楚要旋转的四个数的坐标   点[i][j]，所对应的顺时针旋转90度的点为[j][n-1-i].依次旋转即可。
                temp = matrix[i][j];    
                matrix[i][j] = matrix[matrix.size()-j-1][i];
                matrix[matrix.size()-j-1][i] = matrix[matrix.size()-i-1][matrix.size()-j-1];
                matrix[matrix.size()-i-1][matrix.size()-j-1] = matrix[j][matrix.size()-i-1];
                matrix[j][matrix.size()-i-1] = temp;
            }
        }
        return;
    }
};