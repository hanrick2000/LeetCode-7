//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
//Given n = 3,
//
//You should return the following matrix:
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//]

比spiral matrix I 还简单，循环搞定，关键是要注意当n为奇数时，最后一个数i = (n-1)/2  要小心/2是偶数也有的。

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<int> unit(n);
        vector<vector<int>> res(n, unit);
        int count = 0;
        
        for(int i = 0; i <  (n+1)>>1; ++i) {
            
            if((i<<1)+1 == n ) res[i][i] = ++count;

            for(int j = i; j < n-1-i; ++j) {
                res[i][j] = ++count;
            }
            
            for(int j = i; j < n-1-i; ++j) {
                res[j][n-1-i] = ++count;
            }
            
            for(int j = n-1-i; j > i; --j) {
                res[n-1-i][j] = ++count;
            }
            
            for(int j = n-1-i; j > i; --j) {
                res[j][i] = ++count;
            }
            
        }
        
        return res;
        
    }
};