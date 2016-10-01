//There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
//
//Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.
//
//We keep repeating the steps again, alternating left to right and right to left, until a single number remains.
//
//Find the last number that remains starting with a list of length n.
//
//Example:
//
//Input:
//n = 9,
//1 2 3 4 5 6 7 8 9
//2 4 6 8
//2 6
//6
//
//Output:
//6


//找规律， 1 2 3 4 5 6 7 8 9.  从左到右 就等于 2 4 6 8,  就是2 * （1 2 3 4） 需要对奇偶性和向左向右判断。

class Solution {
public:
    
    int callDp(int len, int dir) {   //len = 0 left  to  right   otherwisw 1
        
        if(len == 1) return 1;
        
        if(len == 2) return 2 - dir;
        
        if(len%2)  return 2*callDp(len/2, 1 - dir);
            
        return 2*callDp(len/2,1-dir) - dir;
    
    }

    int lastRemaining(int n) {
        
        return callDp(n, 0);    
    
    }
};

