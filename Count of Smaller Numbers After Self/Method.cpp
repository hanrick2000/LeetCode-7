You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].

//使用逆序数有经典的解法为合并排序。

struct Node {
    int val;
    int num;
    int index;
    Node():val(0), num(0), index(0) {}
    Node(int v, int n, int i): val(v), num(n), index(i) {}
};

class Solution {
    
    
public:

    void merge(vector<Node>& nums, int start, int mid, int end, vector<Node>& t) {
        int tPos = start, p = start, q = mid+1;
        
        while(p <= mid && q <= end) {
            if(nums[p].val > nums[q].val) {
                t[tPos++] = nums[q++];
            }
            else {  //nums[p] <= nums[q]    当 nums[p] <= nums[q]说明我们可以将q之前的个数都赋值给nums[p]。
                
                t[tPos] = nums[p];
                t[tPos].num += q-mid-1;  //注意这里一定要改的是t数组而不是num.
                tPos++;p++;
            }
        }
        
        while(p<=mid) {  //这里也很容易忘记
            t[tPos] = nums[p];
            t[tPos].num += q-mid-1;
            tPos++;p++;
            
        }
        
        while(q <= end) {
            t[tPos++] = nums[q++];
        }
        
        for(int i = start; i <= end; ++i) {
            nums[i] = t[i];
        }
        
    }


    void mergeSort(vector<Node>& nums, int start, int end, vector<Node>& t) {
        
        if(start >= end) return;
        
        int mid = (start + end)/2;
        
        mergeSort(nums, start, mid, t);
        mergeSort(nums, mid+1, end, t);
        merge(nums, start,mid, end, t);
        
    }

    vector<int> countSmaller(vector<int>& nums) {
        
        vector<Node> tmp(nums.size()), t(nums.size());

        for(int i = 0; i <nums.size(); ++i) {
            
            tmp[i] = Node(nums[i],0,i);  //得记录下标
        }
        
        mergeSort(tmp,0, nums.size()-1, t);
        
        for(int i = 0; i < tmp.size(); ++i) {
            nums[tmp[i].index] = tmp[i].num;
            
        }
        
        return nums;
        
    }
};