//Given an array and a value, remove all instances of that value in place and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//The order of elements can be changed. It doesn't matter what you leave beyond the new length.
//
//Example:
//Given input array nums = [3,2,2,3], val = 3
//
//Your function should return length = 2, with the first two elements of nums being 2.

//很简单，同样用一个count 记录下一个要覆盖的数的位置，同时该count正好记录了新数组的length。

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int count = 0;
        
        for(auto &x: nums) {
            if(x!=val) {
                nums[count++] = x;
            }
        }
        return count;
    }
};