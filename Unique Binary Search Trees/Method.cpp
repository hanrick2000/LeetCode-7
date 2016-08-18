//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
//Given n = 3, there are a total of 5 unique BST's.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3

//这题很直接的，跟节点从1到n的bst共有n种root.  对于每一个root，求出左子树的个数和右子树的个数之积就是结果。递归做


class Solution {
public:
    
    int numTreesHelper(int n, vector<int> &opt) {
        if(n==0||n==1) return 1;
        
        if(opt[n-1]) return opt[n-1];

        int count = 0;
        for(int i = 0; i < n; ++i) {
            count+=numTreesHelper(i,opt)*numTreesHelper(n-i-1,opt);
        }
        
        opt[n-1] = count;
        
        return opt[n-1];

    }
    
    int numTrees(int n) {
        vector<int> opt(n);
        
        return numTreesHelper(n,opt);
        
    }
};