//Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
//
//For example, given the array [2,3,1,2,4,3] and s = 7,
//the subarray [4,3] has the minimal length under the problem constraint.
//
//click to show more practice.
//
//More practice:
//If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

也是一个指针p在后头，一个指针i遍历整个数组。 先设一个sum表示当前p到i subarray中的和，如果sum -= nums[p] >= s, 则循环减，++p，否则跳出循环后如果sum >= s的话，更新p，如果一开始sum小于p,那么也自动跳过while和if进入++i下一个循环。

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int p = 0, sum = 0, mini = nums.size()+1;
        
        for(int i = 0; i < nums.size(); ++i) {
            
            s-=nums[i];
            
            while(s+nums[p]<=0){
                s+=nums[p++];
            }
            
            if(s<=0) {
                mini = min(mini, i-p+1);
            }
        }
        
        return mini%(nums.size()+1);
        
    }
};