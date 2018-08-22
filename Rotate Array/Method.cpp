//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
//
//Note:
//Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
//
//[show hint]
//
//Related problem: Reverse Words in a String II

//最简单的inplace做法，前n-k个翻转，后k个翻转，最后自己来一个大反转。


class Solution {
public:

    void reverse(vector<int>& nums, int p, int q) {
                
        while(p < q) swap(nums[p++],nums[q--]);
        
    }

    void rotate(vector<int>& nums, int k) {
        
        k%=nums.size();
        
        reverse(nums,0,nums.size()-k-1);
        reverse(nums,nums.size()-k,nums.size()-1);
        reverse(nums,0,nums.size()-1);
        
    }
};