//这题新建一个数组，nums[i]表示sum(nums[0]到sum[i]).
//    
//然后这个nums[i]就是sorted. 这样从nums[i]开始往后binary搜索nums[i]+s返回的下标,对应的正好是原始数组中nums[i+1] 到该下标（包括）的subarray 和大于s。
//然后算出相对应subarray的长度，注意，如果返回值在array.size(),表明不存在这样的subarray.


class Solution {
public:

    int binarySearch(int start, vector<int>& nums, int target) {
        int a = start, b = nums.size()-1;
        
        while(a<=b) {//记得一般来说这是=号，返回的是第一个该插入的下标
            int c = (a+b)/2;
            if(nums[c] == target) return c;
            
            if(nums[c] < target) a = c+1;
            
            else b = c-1;
        }
        
        return a;
        
    }

    int minSubArrayLen(int s, vector<int>& nums) {
        
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1];
        }
        
        int mini = nums.size()+1;
        
        for(int i = 0; i < int(nums.size())-1; ++i) {
            
            int target = (i?nums[i-1]:0) + s;
            
            int pos = binarySearch(i, nums, target);
            
            if(pos!=nums.size()) pos = pos-i+1;
            else ++pos;
            
            mini = min(mini, pos);
    
        }
        
        return mini%(nums.size()+1);
        
    }
};