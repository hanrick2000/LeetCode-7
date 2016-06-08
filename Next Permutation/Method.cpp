//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
//The replacement must be in-place, do not allocate extra memory.
//
//Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1

//这道题就是摸清规律。
//请注意以下  例子：
//[4,2,0,2,3,2,0]   3和2换  [4,2,0,3,2,2,0] [2,2,0] 排序  变成 [4,2,0,3,0,2,2]
//[1,3,2]    2和1换 ［2，1，3］ ［1，3］排序
//时间复杂度 O(n^2) 

class Solution {
public:

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void nextPermutation(vector<int>& nums) {
        
        for(int i = nums.size()-2; i>=0; --i) {
            for(int j = nums.size()-1; j > i; --j) {
                if(nums[i] < nums[j]) {
                    swap(nums[i],nums[j]);
                    sort(nums.begin()+i+1,nums.end());  //这一行经常出错！！！
                    return;
                }
            }
        }

        sort(nums.begin(),nums.end());
        
    }
};