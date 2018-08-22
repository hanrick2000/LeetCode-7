//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//
//For example,
//Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
//
//Window position                Max
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
//Therefore, return the max sliding window as [3,3,5,5,6,7].
//
//Note: 
//You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
//
//Follow up:
//Could you solve it in linear time?
//
//Hint:
//
//How about using a data structure such as deque (double-ended queue)?
//The queue size need not be the same as the window’s size.
//Remove redundant elements and the queue should store only elements that need to be considered.

//看了答案，使用双向队列，我们维护一个双向队列，在i循环扫描nums时将下标从头放入，对于i-k以外的窗口外的下标全部弹出。每一次遇见新的i,首先将队首的那些nums[下标]<nums[i]的下标弹出，直到空或者>nums[i],因为这些是不可能成为最大值的。然后压进nums[i].把对于i-k以外的窗口外的下标全部弹出 每一次控制队尾的元素是最大值。
    

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if(!nums.size()) return nums;

        vector<int> res;
        deque<int> Deque;
        
        for(int i = 0; i < nums.size(); ++i) {

            while(Deque.size()&&nums[Deque.front()] < nums[i]) {
                Deque.pop_front();
            }
            
            Deque.push_front(i);
            
            if(i-k == Deque.back()) Deque.pop_back();
            
            if(i-k+1>=0) {
                res.push_back(nums[Deque.back()]);
            }
            
        }
        
        return res;
      
    }
};