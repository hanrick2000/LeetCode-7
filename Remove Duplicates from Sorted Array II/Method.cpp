//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice?
//
//For example,
//Given sorted array nums = [1,1,1,2,2,3],
//
//Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.


two pointer。维护一个pointer i迭代器, 维护一个pointer p, 表示下一个该赋值测位置。维护一个count，纪录这是第几个连续的相同数，如果nums[i]==nums[i-1] count＋＋，如果count不大于2，就把i付给nums[p]。 如果nums[i]!=nums[i-1], 也赋给nums[p], 重调count。

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(!nums.size()) return 0;
        
        int p = 1, count = 1, i = 1;
        
        for(int i = 1; i < nums.size(); ++i) {
            
            if(nums[i] == nums[i-1]) {
                if(++count<=2) {
                    nums[p++] = nums[i];
                }
            }
            else {
                count = 1;
                nums[p++] = nums[i];
            }
        }
        
        return p;
    }
};