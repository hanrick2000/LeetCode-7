//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array nums = [1,1,2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

//显然，这题要用一个count来记录下一次存储新数的位置，我们遇到一个新的数才++count。因为count永远<=i,所以我们可以覆盖nums[count]。


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return {};
        
        int count = 1;
        
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i]!=nums[count-1]) {
                nums[count++] = nums[i];
            }
        }
        
        return count;
    }
};