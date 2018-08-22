//Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//For example, given the array [2,3,-2,4],
//the contiguous subarray [2,3] has the largest product = 6.


//这题显然动态规划，每一次扫描到i时，纪录一个global_max,和global,min. 以i结尾的subarray的最大值和最小值无非两种，以i-1为结尾的局部最大值/最小值 乘以 nums[i]（这里不知道哪一个是最大最小完全是因为nums[i]可正可负） 或者nums[i]. 在纪录一个max来随时更新最大值。初始化局部最大最小为nums[0].
    
    
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if(nums.size() < 1) return 0;
        
        int global_max = nums[0], local_max = nums[0], local_min = nums[0];
        
        for(int i = 1; i < nums.size(); ++i) {
            
            int a = local_max*nums[i], b = local_min*nums[i];
            
            local_max = max(nums[i], max(a,b));
            local_min = min(nums[i], min(a,b));
            
            global_max = max(global_max, local_max);
        }
        
        return global_max;
    }
};