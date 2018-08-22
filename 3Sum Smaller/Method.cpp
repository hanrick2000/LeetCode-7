//Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
//
//For example, given nums = [-2, 0, 1, 3], and target = 2.
//
//Return 2. Because there are two triplets which sums are less than 2:
//
//[-2, 0, 1]
//[-2, 0, 3]
//Follow up:
//Could you solve it in O(n2) runtime?

//O(n^3)不用说了 狗也会。关键是如何用O(n^2). 老样子还是2 pointer.其中一个i从0到n-2,表示最小的下标，剩下的i+1到n就首尾用2 pointer。如果nums[p] + nums[q] < target-nums[i], 表明 (p,p+1), (p,p+2), ... (p,q) 这q-p组都是解，直接++p, 否则就--q,一直循环直到p>=q;
//这样总共n^2

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        
        int res = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < int(nums.size())-2; ++i) {
            int p = i+1, q = nums.size()-1;
            
            while(p<q) {
                if(nums[p] + nums[q] < target-nums[i]) {
                    res+=q-p;
                    ++p;        
                }
                else {
                    --q;
                }
            }
        }
        
        return res;
        
    }
};