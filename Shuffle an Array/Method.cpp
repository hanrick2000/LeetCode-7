//Shuffle a set of numbers without duplicates.
//
//Example:
//
//// Init an array with set 1, 2, and 3.
//int[] nums = {1,2,3};
//Solution solution = new Solution(nums);
//
//// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
//solution.shuffle();
//
//// Resets the array back to its original configuration [1,2,3].
//solution.reset();
//
//// Returns the random shuffling of array [1,2,3].
//solution.shuffle();

//该题，先从1到n随机选一个数放置到最后一个位置，然后再1~n-1中随机选一个数放到倒数第二个位置。。。

class Solution {
    vector<int> mynums;
    vector<int> newnums;
public:
    Solution(vector<int> nums) {
        mynums = nums;
        newnums = nums;
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return mynums;
    }
    
    /** Returns a random shuffling of the array. */
    
    vector<int> shuffle() {
        
        for(int i = newnums.size()-1; i >= 0; --i) {
            int j = rand()%(i+1);
            swap(newnums[i], newnums[j]);
        }
        
        return newnums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */