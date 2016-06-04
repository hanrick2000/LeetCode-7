//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note:
//Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//The solution set must not contain duplicate triplets.



// 可以先对数组排序，然后两重循环便利数组，对剩下的部分用二分查找，找target-a-b。 值得注意的是，为了防止重复，每一次遍历时,i,j都要确保和上次不同。
//复杂度 O(nlogn+n^2logn) = O(n^2lgn).

class Solution {
public:

    bool binarySearch(vector<int>& nums, int start, int target) {
        
        int p = start, q = nums.size()-1,c;
        
        while(p <= q) {
            c = (q-p)/2+p;
            if(nums[c] == target) return true;
            else if(nums[c] < target) p = c+1;
            else q = c-1;
        }
        return false;
    }

    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size()<3) return {};
        
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < nums.size()-2; ++i) {
            if(i && nums[i] == nums[i-1]) continue; 
            
            for(int j = i+1; j < nums.size()-1; ++j) {
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                if(binarySearch(nums,j+1,-nums[j]-nums[i])) {
                    res.push_back({nums[i],nums[j],-nums[j]-nums[i]});
                }
            }
        }

        return res;
        
    }
};