//Given a positive integer n and you can do operations as follow:
//
//If n is even, replace n with n/2.
//If n is odd, you can replace n with either n + 1 or n - 1.
//What is the minimum number of replacements needed for n to become 1?
//
//Example 1:
//
//Input:
//8
//
//Output:
//3
//
//Explanation:
//8 -> 4 -> 2 -> 1
//Example 2:
//
//Input:
//7
//
//Output:
//4
//
//Explanation:
//7 -> 8 -> 4 -> 2 -> 1
//or
//7 -> 6 -> 3 -> 2 -> 1

//用动态规划+memo的思想即可。

class Solution {
public:

    int integerReplacementHelper(long long n, unordered_map<int,int> &m)  {
        if(m.find(n)!=m.end()) return m[n];
        
        if(n%2) {
             m[n] = 1 + min(integerReplacementHelper(n+1,m),integerReplacementHelper(n-1,m));
             return m[n];
        }
        
        m[n] = 1 + integerReplacementHelper(n/2, m);
        
        return m[n];
    }

    int integerReplacement(int n) {
        
        unordered_map<int,int> m;
        m[1] = 0;
        
        return integerReplacementHelper(n, m);
    }
};
