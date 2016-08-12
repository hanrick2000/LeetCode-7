//Follow up for "Search in Rotated Sorted Array":
//What if duplicates are allowed?
//
//Would this affect the run-time complexity? How and why?
//
//Write a function to determine if a given target is in the array.

//这种做法道理很直观，  我们能先找到这个数组中的极大值在哪。  然后将数组从极大值点分成左右两部分。这样两部分都是sorted了。所以就进行两部分二分查找即可。

//所以重点在与如何find peak? 由于这道题是的有序不是严格的，找peak 无法简单的通过nums[middle] 和 nums[start] 的> <关系去判断peak是否在区间， 因为如果nums[middle] 可以== nums[start]和nums[end]. 当这种情况发生时 还要同时对两遍递归进行find peak.   例如1,1,1,1,0,1,1,1 和 1,1,1,0,1,1,1,1 这两种情况，一个peak 在左边  一个在右边. 
//所以最坏情形 需要O(n)的时间复杂度去找到peak, 然后在用O(log n)的二分查找即可。
//

class Solution {
public:

    bool findPeak(vector<int>& nums, int p, int q, int &peak) {   //找到某一个index 使得   nums[index]>nums[index+1]    不存在 index 就为最后一个数
        if(q <= p+1) {  // 递归到只有一个数
            return false; 
        }
        
        if(q == p +2) { //递归到只有两个数
            if (nums[p] > nums[q-1]) { //找到peak
                peak = p;
                return true;
            }
            return false;
        }
        
        // 能走到这表明  q >= p+3 
        bool f = false;
        int c = (p+q)/2;
        if(nums[p] >= nums[c]) {  //peak有可能在这里
            f = findPeak(nums, p, c+1, peak);
        }
        
        if(!f&&nums[c] >= nums[q-1]) {
            f = findPeak(nums, c, q, peak);
        }
        
        return f;
        
    }
    
    
    bool binarySearch(vector<int>& nums, int p, int q, int target) {
        
        while(p <= q) {
            int c = (p+q)/2;
            if(nums[c] == target) return true;
            if(nums[c] < target) {
                p = c+1;
            }
            else {
                q = c-1;
            }
        }
        return false;
        
    }

    bool search(vector<int>& nums, int target) {
        
        int peak = nums.size()-1;
        findPeak(nums, 0, nums.size(), peak);
        
        bool f = binarySearch(nums, 0, peak, target);
        
        if(!f) {
            return binarySearch(nums, peak+1, nums.size()-1, target);
        }
        
        
        return f;
        
    }

};