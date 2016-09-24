//Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
//Formally the function should:
//Return true if there exists i, j, k 
//such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
//Your algorithm should run in O(n) time complexity and O(1) space complexity.
//
//Examples:
//Given [1, 2, 3, 4, 5],
//return true.
//
//Given [5, 4, 3, 2, 1],
//return false.


//时刻维护两个指针保持最小的1升序 位置 和 2升序位置。


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        if(!nums.size())  return false;
        
        int twoindex = -1, oneindex = 0;
        
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < nums[oneindex]) oneindex = i;
            
            else if(nums[i] > nums[oneindex]){
                if(twoindex == -1) {
                    twoindex = i;
                }
                else {
                    if(nums[i] > nums[twoindex]) return true;
                    
                    else twoindex = i;
                    
                }
            }
        }
        
        return false;
    }
};
