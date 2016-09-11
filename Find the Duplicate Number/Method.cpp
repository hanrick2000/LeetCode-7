//Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
//
//Note:
//You must not modify the array (assume the array is read only).
//You must use only constant, O(1) extra space.
//Your runtime complexity should be less than O(n2).
//There is only one duplicate number in the array, but it could be repeated more than once.


//这题提示用binary search, 但是有没有拍完序的数组，该对谁二分呢？其实可以对1,...,n进行二分，每一次我们取中间一个数，对小于中间这个数，大于左端点的值进行计数，看看它是不是等于这段线段差。每一次我们都可以减半所以是O(nlgn).


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int a = 1, b = nums.size()-1;
    
        while(a < b) {  //防止死循环
            
            int c = (a+b+1)/2;  //防止死循环
            int count = 0;
            
            for(auto x: nums) {
                if(x >=a && x < c) ++count;
            }
            
            if(count > c - a) {
                b = c-1;
            }
            
            else {
                a = c;
            }
        }
        return a;
        
    }
};