//Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
//
//Note:
//The array size can be very large. Solution that uses too much extra space will not pass the judge.
//
//Example:
//
//int[] nums = new int[] {1,2,3,3,3};
//Solution solution = new Solution(nums);
//
//// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
//solution.pick(3);
//
//// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
//solution.pick(1);

//蓄水池抽样，要从一个数据流中等概率抽取k个数，第一个数，全概率选上，第二个数以二分之一概率替换它。第三个数以1/3概率替换... 耗时O(n).

class Solution {
    vector<int> n;
public:
    Solution(vector<int> nums): n(nums) {
        srand (time(NULL));
    }
    
    int pick(int target) {
        
        int c = 1, p = -1;
    
        for(int i = 0; i < n.size(); ++i) {

            if(n[i] == target) {
                if(rand()%c == 0) p = i;
                ++c;
            }
        }
        return p;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */