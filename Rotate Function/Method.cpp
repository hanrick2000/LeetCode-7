//Given an array of integers A and let n to be its length.
//
//Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:
//
//F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
//
//Calculate the maximum value of F(0), F(1), ..., F(n-1).
//
//Note:
//n is guaranteed to be less than 105.
//
//Example:
//
//A = [4, 3, 2, 6]
//
//F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
//F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
//F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
//F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
//
//So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.

//先求不转的那个和，可以发现每次一转，相当于减掉A的全部和，再加上(n+1)*某一个A元素的。所以我们先求前缀和，然后再扫一遍，计算差值。O(n)


class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        
        int tmp = 0, maxi = INT_MIN;
        
        vector<int> B(A);
        
        for(int i = 1; i < B.size(); ++i) {
            B[i]+= B[i-1];
        }
        
        for(int i = 0; i < A.size(); ++i) {
            tmp += A[i]*i;
        }
        
        maxi = max(maxi,tmp);
        
        for(int i = 0; i < int(A.size())-1; ++i) {
            tmp += -B.back()+(B.size())*A[i];
            maxi = max(maxi, tmp);
        }
        
        return maxi;
    }
};