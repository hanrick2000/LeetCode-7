//
//Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
//
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that num[-1] = num[n] = -∞.
//
//For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
//
//click to show spoilers.
//
//Note:
//Your solution should be in logarithmic complexity.

很简单，二分，比较nums[c]和nums[c+1],如果前者大，说明peak在前面，否则peak在后面。

class Solution {
public:
    
    int findPeakElement(vector<int>& nums) {
        
        int a = 0, b = nums.size()-1;
        
        while(a<b) {  //这个条件可以根据两，三个数测试会不会死循环得出
        
            int c = (a+b)/2;
            
            if(nums[c] < nums[c+1]) {
                a = c+1;
            }
            
            else {
                b = c;
            }
        }
        
        return a;
        
    }
};