//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//You may assume no duplicate exists in the array.

//二分法，找到根据断点左还是在右进行递归，不过还得注意可能没有转过，就是第一个值。一定要注意递归出口，否则会死循环。

class Solution {
public:
    
    int findMinHelper(vector<int>& nums, int start, int end) {
        
        if(start+1==end) return nums[start];
        
        if(start + 2 == end) return min(nums[start],nums[start+1]);
        
        int mid = (start + end)/2;
        
        if(nums[start] > nums[mid]&&nums[mid]<nums[end-1]) {
            return findMinHelper(nums,start,mid+1);
        }
        
        if(nums[start]<nums[mid]&&nums[mid]>nums[end-1]) {
            return findMinHelper(nums, mid, end);
        }
        
        return nums[start];
        
    }

    int findMin(vector<int>& nums) {
        
        return findMinHelper(nums, 0, nums.size());

    }
};


//附上迭代版本：
class Solution {
public:

    int findMin(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        
        int a = 0, b = nums.size()-1;
        
        while(b > a + 1) {
            int c = (a+b)/2;
            if(nums[a] > nums[c]&&nums[c]<nums[b]) {
                b = c;
            }
            
            else if(nums[a]<nums[c]&&nums[c]>nums[b]) {
                a = c;
            }
            else {
                return nums[a];
            }
        }
        
        return min(nums[a],nums[b]);
        
    }
};