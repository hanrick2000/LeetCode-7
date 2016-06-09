//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.

//该方法是递归法。  devide and conqur 
//首先根据二分点 nums[middle] 与  nums[start] 来判断  究竟左边是sorted 还是 右边是sorted。然后分两种根据待查值和sorted 两端的关系，取一段递归进行。 时间O(lgn)


class Solution {
public:

    int binarySearch(vector<int>& nums, int target, int start, int end) {
        while(start < end) {
            int middle = (start + end)/2;
            if(nums[middle] == target) return  middle;
            
            else if(nums[middle] < target) start = middle +1;
            else end = middle -1;
        }
        return nums[start] == target? start: -1; 
    }

    int searchHelper(vector<int>& nums, int target, int start, int end) {
        // if(start == end) return -1;
        if(start == end-1) return nums[start] == target? start:-1;
        int middle = (start + end)/2;

        if(nums[middle] > nums[start]) {
        
            if(target >= nums[middle] || target < nums[start]) return searchHelper(nums, target, middle, end);
            
            else return binarySearch(nums, target, start, middle-1);
        }
        
        else {
                    
            if(target >= nums[middle] && target < nums[start]) return binarySearch(nums, target, middle, end-1);
            
            else return searchHelper(nums, target, start, middle);
        }
    }

    int search(vector<int>& nums, int target) {
        
        return searchHelper(nums, target, 0, nums.size());
        
    }
};