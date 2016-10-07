//Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.
//
//Example:
//Given matrix = [
//  [1,  0, 1],
//  [0, -2, 3]
//]
//k = 2
//The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
//
//Note:
//The rectangle inside the matrix must have an area > 0.
//What if the number of rows is much larger than the number of columns?


//这题思想是这样的。我们先要求解一个降维问题，在一个一维数组里面找一个subarray使得它的和不超过k。我们可以从左到右一个循环，一遍遍历数组，求当前的前缀和sums[i], 一遍求之前的sums[j] 使得 sums[i]-sums[j] <=k 即  sums[j] >= sums[i] - k. 可以用C++ set里的lower_bound。注意如果没有找到这样的元素要判断返回的迭代器it是否是set.end().一开始set里得加入0,同时每一次循环后把新的sum扔进set.所以对于长度为n的数组，复杂度是nlogn.
//
//题目告诉我们行数会远远多余列数。那么我们可以把矩阵的每一列作为一个数组，扔进上述一维算法。然后通过一个2次循环迭代所有的列i和列j, 把列i到列j的之间的作为一个数组，进行计算。可以通过求前缀和的方式用O(mn)计算，使得array[i][j]保存的是matrix[i][0]到mattix[i][j]这一行的元素和，然后我们就可以用 array[i][j] - array[i][k]得到k+1列到j列之间的元素和，放到一个数组中，就可以计算最靠近k的值，
//假设m行n列，复杂度n^2*mlogm. 
    
class Solution {
public:
    
    int maxSumSubarray(vector<int> &array, int k) {
        
        multiset<int> myset;
        myset.insert(0);
        int sum = 0;
        int res = INT_MIN;
        
        for(int i = 0; i < array.size(); ++i) {
            sum += array[i];
            
            auto it = myset.lower_bound(sum - k);

            if(it!=myset.end()) res = max(res, sum - *it);
            
            myset.insert(sum);
        }
        return res;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int res = INT_MIN;
     
        for(int i = 1; i < matrix[0].size(); ++i) {
            for(int j = 0; j < matrix.size(); ++j) {
                matrix[j][i] += matrix[j][i-1];
            }
        }
    
        for(int i = 0; i < matrix[0].size(); ++i) {
            
            vector<int> array(matrix.size());
            
            for(int j = 0; j < matrix.size(); ++j) {
                array[j] = matrix[j][i];
            }
            
            res = max(res, maxSumSubarray(array,k));

            for(int j = i+1; j < matrix[0].size(); ++j){
                vector<int> array2(matrix.size());
                for(int k = 0; k < array2.size(); ++k) array2[k] = matrix[k][j] - matrix[k][i];
                res = max(res, maxSumSubarray(array2,k));
            }
        }

        return res;
    }
};