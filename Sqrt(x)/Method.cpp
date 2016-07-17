//Implement int sqrt(int x).
//
//Compute and return the square root of x.

//很简单的二分思想，在1到target中二分 只需把二分法中target 与 c*c相比即可， 标准的二分法写完，退出循环后的a总是只想target被插入的位置，所以a-1正好是最后一个c*c小于target的数，就是我们要求的。
同时我们要注意c*c会溢出，我们可以转为long long 或double都可以的

class Solution {
public:

    int binarySearch(int target) {
        int a = 1, b = target;
        
        while(a<=b) {
            int c = (b-a)/2+a;
            double temp = double(c)*c;
            if(temp == double(target)) return c;
            else if(temp < double(target)) a = c +1;
            else b = c - 1;
        }
        
        return a-1;
    }

    int mySqrt(int x) {
        if(x<2) return x;
        
        return binarySearch(x);
        
    }
};