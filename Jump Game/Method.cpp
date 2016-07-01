//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example:
//A = [2,3,1,1,4], return true.
//
//A = [3,2,1,0,4], return false.


//这题提示用greedy。  怎么个greedy呢？如果从起点开始每一次都选择最远的点跳那么很可能会“回溯”，最简单 比如：3 3 1 0 0. 当我们在第一个3时，如果跳3格，就会卡死。正确的是跳1格。
//如果用回溯法， 很可能是指数型复杂度。
//那我们应该怎么个greedy法呢？我们从终点出发，依次往前寻找第一个点，使得能在该点跳到终点。现在考察这个点，如果我们能够跳到这个点，就意味着我们能跳到终点，反之，如果我们不能跳到这个点，我们也无法跳到终点。（这是为什么？因为假设有一个点能跳到终点，为啥我们到不了更近的点？）所以能跳到这个点和跳到终点是等价的，这个点相当于前脚石。于是我们可以迁移终点，依次类推，如果我们能够一直前移到起点，那么就有解。否则中间一旦到某一步我们找不到这个前脚点,那么就宣告失败。时间复杂度O(n).

class Solution {
public:

    bool canJump(vector<int>& nums) {
        
        int i = nums.size()-1,j;
        while(i != 0) {
            for(j = i-1; j > -1; --j) {
                if(nums[j] >= i-j) {
                    i = j;
                    break;
                }
            }
            if(j == -1) return false;
        }
        return true;
    }
};