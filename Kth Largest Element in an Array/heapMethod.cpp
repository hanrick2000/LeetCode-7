//Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//For example,
//Given [3,2,1,5,6,4] and k = 2, return 5.
//
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ array's length.

//用堆是最直接的，求第k大，小顶堆又比大顶堆直接。先让数组前k个数建小顶堆，完了后，就先假设堆顶是第k大的，那么如果后面n-k个数比堆顶大的话，就弹出当前堆顶，插入该数，然后维护堆得构造。所以这个堆里面始终维护着当前前k大的数。并且k是正好在堆顶。 O(k) +(n-k)（lg k) )
//同理用大顶堆就是维护当前前n-k+1 个小的数，那么堆顶这个数也正好是第k大。
O(n-k) + klg(n-k)
    
//最坏情况当k = 1/2 nlg n.


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        if(!nums.size()) return 0;
        
        priority_queue<int,vector<int>> heap(nums.begin(),nums.begin()+nums.size()-k+1);
        
        for(int i = nums.size()-1; i >= heap.size(); --i) {

            if(nums[i] < heap.top()) {
                int top = heap.top();
                heap.pop();
                heap.push(nums[i]);
                nums[i] = top;
            }
        }
        
        return heap.top();
        
    }
};