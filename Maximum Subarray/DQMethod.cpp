//该方法是分治法。我们知道，一个数组的最大连续子数组只能出先在左数组，右数组以及穿插中线的数组三种情况，左右两边可以递归进行,所以关键我们要求中线，中线规定了左右两数组都要至少抽一个数出来，所以我们按这两个数往两头顺序扫描，叠加起来，求最大值，再把左右两边加起来就好。
//T(n) = 2T(n/2) + O(n) 标准的 nlogn. 

class Solution {
public:
    int maxSubArrayHelper(vector<int>& nums, int start, int end) {  //end 指在最后元素后的位置
        
        if(start+1>end) return 0;
        if(start+1 == end) return nums[start];
        
        int mid = (start + end)/2;
        
        int left = maxSubArrayHelper(nums,start,mid);
        int right = maxSubArrayHelper(nums,mid,end);
        
        int maxi = nums[mid-1],sum = maxi;
        for(int i = mid-2; i >=start; --i) {
            sum += nums[i];
            maxi = max(maxi, sum);
        }
        int maxi2 = nums[mid], sum2 = maxi2;
        
        for(int i = mid+1; i < end; ++i) {
            sum2 += nums[i];
            maxi2 = max(maxi2, sum2);
        }
        
        return max(max(left,right),maxi+maxi2);
        
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums,0,nums.size());
    }
};