//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example:
//Given array A = [2,3,1,1,4]
//
//The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//
//Note:
//You can assume that you can always reach the last index.

该题是jump game I 的变种，求的是最少跳的次数。也是用贪心法，不过贪心思路和jump game I不同。该问题可以把每一个nums[i] 看成一个 起点是i，长度是nums[i]的区间，问题就是找到最少的区间，覆盖整个[0,n-1]. 贪心思路是，将这些区间按起点大小排序（不过由于这些点的起点就是下标，已经保证有序），然后从区间0开始，顺序往下找，找到与该区间重叠且终点值最大的区间，这就是下一次要“跳”的起点。循环往复。

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        
        int pre = 0, step = 1;
        
        int maxi = -1,index = -1;
        
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[pre]+pre >=  nums.size()-1) break;
            if(i<=nums[pre]+pre) {
                if(nums[i]+i > maxi) {
                    maxi = nums[i]+i; 
                    index = i;
                }
            }
            else {
                pre = index;
                ++step;
                index = maxi = -1;
                --i;
            }
        }     

        return step;
        
    }
    
    int jump(vector<int>& nums) {
        
        int end = 0, step = 0, curEnd = 0;
        //curEnd表示当前step下能跳到的最远index。如何寻找下一个step下能跳到的最远位置？ 依次看每一个i<=curEnd, 看看i + nums[i]的最大值就是下一个step 能跳到的最远位置。
        for(int i = 0; i < nums.size(); ++i) {
            if(curEnd >= nums.size()-1) return step;
            if(i<=curEnd) {
                if(i + nums[i] > end) end = i + nums[i];
            } else {
                if(end == curEnd) return -1; // 说明上一次能跳到的最大距离并没有更新，即无法跳到 i这个点。如果不退出，就是死循环在之前的地方无穷跳下去
                curEnd = end;
                step++;
                --i;//这句话极容易漏
            }
        }
        
        return step;
    }
};