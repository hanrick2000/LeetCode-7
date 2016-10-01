//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
//Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//For example,
//Given heights = [2,1,5,6,2,3],
//return 10.

这题用一个栈来维护所有矩形向左到右高度递增的序列。1）栈空肯定加入当前的矩形下标2）当前矩形比栈顶矩形高度高   否则一直退栈，直到栈空或者栈顶矩形高度小于当前矩形。  最后再加入当前矩形。 问题是   退栈时我们要做哪些工作？
    
//肯定是计算当前矩形向两边延展的最大矩形，我们知道退栈的矩形肯定能向右够延伸到当前矩形的前一个位置，所以这个下标是i肯定确定了，那它能向左延伸到哪呢？肯定是到计算它时那时刻栈顶前的矩形的前面一个位置。如果栈是空，那么他一直能够延伸到0的位置（所有矩形的前面）。所以时间复杂度总共(O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> mystack;
        heights.push_back(0);
        
        int res = 0;
        
        for(int i = 0; i < heights.size(); ++i) {
         
            while(mystack.size()&& heights[i] < heights[mystack.top()]) {
                    
                int index = mystack.top();
                
                mystack.pop();
                    
                res = max(res, heights[index] * (i - (mystack.size()?mystack.top()+1: 0)));
            }
                
            mystack.push(i);

        }
        
        return res;
        
        
    }
};

