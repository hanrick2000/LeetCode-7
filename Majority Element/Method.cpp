//Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//
//You may assume that the array is non-empty and the majority element always exist in the array.


//先假设第一个数是众数，记录count = 1, 以后每一次遇到一个数，如果不是当前众数，就--count, 如果count小于0了就要交换众数，设为当前数，再把count设为1.最后返回当前众数。该方法仅对唯一存在众数有效。

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int maj = nums[0], count = 1;
        
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == maj) ++count;
            
            else {
                if(--count<0) {
                    maj = nums[i];
                    count = 1;
                }
            }
            
        }
        
        return maj;
        
    }
};