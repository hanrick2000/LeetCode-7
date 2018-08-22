//Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
//
//Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//
//Example:
//
//matrix = [
//   [ 1,  5,  9],
//   [10, 11, 13],
//   [12, 13, 15]
//],
//k = 8,
//
//return 13.
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ n2.

//这题我们也可以用二分查找法来做，我们由于是有序矩阵，那么左上角的数字一定是最小的，而右下角的数字一定是最大的，所以这个是我们搜索的范围，然后我们算出中间数字mid，由于矩阵中不同行之间的元素并不是严格有序的，所以我们要在每一行都查找一下mid，我们使用lower_bound，这个函数是查找第一个大于等于目标数的元素，如果目标数在比该行的尾元素大，则lower_bound返回该行元素的个数，如果目标数比该行首元素小，则lower_bound返回0, 我们遍历完所有的行可以找出中间数是第几小的数，然后k比较，进行二分查找，本解法的整体时间复杂度为O(nlgn*lgX)，其中X为最大值和最小值的差值，参见代码如下：


class Solution {
public:

    int search(vector<int> &v, int target) {

        int p = 0, q = int(v.size())-1;
        
        while(p < q) {
            
            int c = (p+q)/2;
            
            if(v[c] < target) {
                p = c+1;
            }
            
            else {
                q = c;
            }
        }
        
        return v[p] >= target? p: p+1;
        
    }


    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        if(!matrix.size() || !matrix[0].size()) return -1;
        
        int p = matrix[0][0], q = matrix.back().back(), k2 = -1;
        
        while(p < q) {
                
            int c = (p+q+1)/2;
                
            k2 = 1;
                
            for(auto x: matrix) {
                    
                k2 += search(x, c);
    
            }
                
            if(k < k2) {
                q = c - 1;
            }
                
            else {
                p = c;
            }

        }
            
        return p;
        
    }
};