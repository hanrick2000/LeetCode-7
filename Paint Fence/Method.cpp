//There is a fence with n posts, each post can be painted with one of the k colors.
//
//You have to paint all the posts such that no more than two adjacent fence posts have the same color.
//
//Return the total number of ways you can paint the fence.
//
//Note:
//n and k are non-negative integers.

//看图找规律，发现通项公式是 nk = (k-1)(n[k-1] + n[k-2])

class Solution {
public:
    int numWays(int n, int k) {
        if(n==0) return 0;
        if(n==1) return k;
        
        int n1 = k, n2 = k*k;
        
        for(int i = 2; i < n; ++i) {
            int n = (k-1)*(n1+n2);
            n1 = n2;
            n2 = n;
        }
        
        return n2;
        
    }
};