//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//Given the following matrix:
//
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//You should return [1,2,3,6,9,8,7,4,5].
//
//Show Company Tags
//Show Tags
//Show Similar Problems


//思路很简单的一道题，但要仔细考虑最后一下 可能是一个数  ，一个行向量  或者一个列向量的特殊情形。

class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        if(!matrix.size()||!matrix[0].size()) {
            return {};
        }
        
        vector<int> res;
        
        int minlen = min(matrix.size(),matrix[0].size());
        
        for(int i = 0; i < (minlen+1)/2; ++i) {
            
            if(matrix.size()%2 && matrix.size() == matrix[0].size() && i == matrix.size()/2) {
                res.push_back(matrix[i][i]);
            }
            
            else if(matrix.size()%2 && i == matrix.size()/2) {
                for(int j = i; j < matrix[0].size()-i; ++j) {
                    res.push_back(matrix[i][j]);
                }
            }
            
            else if(matrix[0].size()%2 && i == matrix[0].size()/2) {
                for(int j = i; j < matrix.size()-i; ++j) {
                    res.push_back(matrix[j][i]);
                }
            }
            else {
                for(int j = i; j < matrix[0].size()-i-1; ++j) {
                    res.push_back(matrix[i][j]);
                }
                for(int j = i; j < matrix.size()-i-1; ++j) {
                    res.push_back(matrix[j][matrix[0].size()-i-1]);
                }
                for(int j = matrix[0].size()-i-1; j > i; --j) {
                    res.push_back(matrix[matrix.size()-i-1][j]);
                }
                for(int j = matrix.size()-i-1; j > i; --j) {
                    res.push_back(matrix[j][i]);
                }                
            }
            
        }
        return res;
        
    }
};