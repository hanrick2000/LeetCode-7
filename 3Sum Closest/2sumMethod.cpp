//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//    For example, given array S = {-1 2 1 -4}, and target = 1.
//
//    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

//该方法由2sum 稍作改变，只要找到2sum closest 就可以。

class Solution {
public:

    void twoSum(vector<int>& nums, int start, int target, int &min, int &res, int f) {
        int p = start, q = nums.size()-1,temp;
        while(p < q) {
            temp = nums[p] + nums[q] - target;
            
            if(abs(temp)<min) { //更新 min 
                min = abs(temp);
                res = nums[p] + nums[q] + f;
            }
            
            if(temp < 0) p++;
            
            else if (temp > 0) q--;
            
            else return;   //找到target 可以直接返回。
        }
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        
        if(nums.size()<3) return {};
        
        sort(nums.begin(),nums.end());
        
        int min = abs(nums[0]+nums[1]+nums[2]-target)+1;  //定义一个足够大的初始值
        int res;
        
        for(int i = 0; i<nums.size()-2; ++i) {
            if(i && nums[i] == nums[i-1]) continue; 
            twoSum(nums,i+1,target-nums[i],min,res,nums[i]);
            if(!min) return res;   //如果正好找到target，那么可以直接返回
        }
        
        return res;
    }
};