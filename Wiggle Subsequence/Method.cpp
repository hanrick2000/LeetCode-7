//A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.
//
//For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.
//
//Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.
//
//Examples:
//Input: [1,7,4,9,2,5]
//Output: 6
//The entire sequence is a wiggle sequence.
//
//Input: [1,17,5,10,13,15,10,5,16,8]
//Output: 7
//There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
//
//Input: [1,2,3,4,5,6,7,8,9]
//Output: 2
//Follow up:
//Can you do it in O(n) time?



//dp: 用一个数组记录每一个每一个数结尾时，到它是升序的最大值 和到它是结尾的最大值。用dp可以O(n^2)做完

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(!nums.size()) return 0;
        
        vector<pair<int,int>> dp(nums.size());  //1表示上升 
        
        dp[0] = make_pair(1,1);       //1.dayu 2xiaoyu
        
        for(int i = 1; i < nums.size(); ++i) {

            int maxi1 = 1, maxi2 = 1;
            
            for(int j = i-1; j >= 0; --j) {
                
                if(nums[i] > nums[j]) {
                    maxi1 = max(maxi1, dp[j].second + 1); 
                }
                
                else if(nums[i] < nums[j]) {
                    maxi2 = max(maxi2, dp[j].first + 1);
                }
            }
            
            dp[i] = make_pair(maxi1,maxi2);
        }
        
        return max(dp.back().first,dp.back().second);
    }
};

//只要不要连续出现3个数（上升）或者下降就好，要严格的，如果看到前后两个数一样  直接忽略。一定要考虑相等情况。


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(!nums.size()) return nums.size();

        int ascending = 0, cur = 1;
        
        for(int i = 1; i < nums.size(); ++i) {
            
            if(nums[i] < nums[i-1]) {
                if(ascending != -1) ++cur;
                
                ascending = -1;
            }
            
            else if(nums[i] > nums[i-1]) {
                if(ascending != 1) ++cur;
                
                ascending = 1;
            }
        }
        
        return cur;
    }
};

