//本方法是迭代法。思路和上次的递归法一摸一样，仔细看看和二分法真的很想呢。

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int p = 0, q = nums.size()-1;
        
        while(p < q) {
            int c = (p+q)/2;
            
            if(nums[c] < nums[p]) {
                if(nums[c] == target) return c;
                else if(nums[c] < target&&target<=nums[q]) p = c+1;
                else q = c-1;
            }
            
            else {
                if(nums[c] == target) return c;
                else if(nums[c] < target||target<nums[p]) p = c+1;
                else q = c-1;
            }
        }
        
        return nums[p] == target? p:-1;
    }
};