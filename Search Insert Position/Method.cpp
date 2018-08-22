//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Here are few examples.
//[1,3,5,6], 5 → 2
//[1,3,5,6], 2 → 1
//[1,3,5,6], 7 → 4
//[1,3,5,6], 0 → 0

//一定要滚瓜烂熟，养成机械记忆的一道题，这就是教科书式的二分查找！！！
//要写二分查找， 不要再写p<q了，  写p<=q ,  p,q两指针一定是指向头尾元素的。c 永远是(p+q)/2版本。
//循环结束后永远是p == q + 1; p永远是插入位置 因为出来后  q永远是比该数小的最后一个位置，p永远是比该数大的第一个位置，所以p该数是插入位置。

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int p = 0, q = nums.size()-1,c;
        
        while(p <= q) {
            c = p + (q-p)/2;
            if(nums[c] == target) return c;
            else if(nums[c] < target) p = c+1;   //p指向右边数组的第一个元素
            else q = c-1;  //q指向左边数组的最后一个元素
        }
        return p;
    }
};