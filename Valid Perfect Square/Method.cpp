//Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
//Note: Do not use any built-in library function such as sqrt.
//
//Example 1:
//
//Input: 16
//Returns: True
//Example 2:
//
//Input: 14
//Returns: False

//先求平方根，然后看看平方根的平方是不是本身。


class Solution {
public:

    int mysqrt(int a) {
        int p = 0, q = a;
        
        while(p < q) {
            int c = (p+1-q)/2 + q;   //注意这里处理不要死循环  也不要溢出。
            
            if(c == a/c) return c;
            
            if(c > a/c) q = c-1;
            
            else p = c;
        }
        return p;        
    }

    bool isPerfectSquare(int num) {
        
        if(num < 0) return false;
        
        int root = mysqrt(num);
        
        return root*root == num;
    }
};