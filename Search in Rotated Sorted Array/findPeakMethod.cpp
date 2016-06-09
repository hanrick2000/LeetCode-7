//这种做法道理很直观，  我们能先找到这个数组中的极大值在哪。  然后将数组从极大值点分成左右两部分。这样两部分都是sorted了。所以就进行两部分二分查找即可。时间复杂度O(log n)
//

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        if(start>end) return -1;   //这步完全是由于peak的定义导致 可能出现start > end的
        
        while(start < end) {
            int middle = (start + end)/2;
            if(nums[middle] == target) return  middle;
            
            else if(nums[middle] < target) start = middle +1;
            else end = middle -1;
        }
        return nums[start] == target? start: -1; 
    }

    int findPeak(vector<int>& nums) {    //peak 是max点的index。如果没有（即有序的） 就是最后一个数. 特别的，1个数 就是本身0
        
        int p = 0,  q = nums.size()-1;
        while(p+1<q) {    // 这个循环可以从图中看出来
            int c= (p+q)/2; // 当q == p + 2时 c = p+1 下次循环必定跳出
            
            if(nums[c] > nums[p]) p = c;  // 需要指出  为什么这里不会出现死循环？
            else q = c-1;
            
        }
        
        return nums[p] > nums[q] ? p:q;
        
    }

    int search(vector<int>& nums, int target) {
        
        // return findPeak(nums);  
        
        int peak = findPeak(nums);    //peak 是max点的index。如果没有 就是最后一个数. 1个数 就是本身0
        
        int res1 = binarySearch(nums,target,0,peak);
        if(res1!=-1) return res1;
        
        return binarySearch(nums,target,peak+1,nums.size()-1);
    }
};