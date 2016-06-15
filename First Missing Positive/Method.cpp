//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//Given [1,2,0] return 3,
//and [3,4,-1,1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space.

//本题我的第一反应就是用一个数组，在位置(i) 记录 数值i。然后，我们从数组索引1头出发，只要找到了第一个i!=nums[i], 这就是第一个丢失的正数。
//    
//但是如何才能使用constant 空间呢？明显能采用原数组的空间，但是如果数组中出现的数字非常大呢？比如10000，就得放在nums[10000]位置了，但是原数组长度很可能没那么大。我们仔细看这个问题，就可以发现超过原数组长度的那些数我们可以忽略。理由：数组中所有的正整数个数<=数组长度，所以第一个遗失的数必定小于等于数组长度，所以，大于长度那些数我们可以忽略。  
//
//因此我们的算法：nums[i] 换到 nums[nums[i]]去。当nums[nums[i]] 与nums[i] 一样时，就不用换了。

//这种做法和sortcolor很像

class Solution {
public:

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int firstMissingPositive(vector<int>& nums) {
        
        nums.push_back(-1);
        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i]&&nums[i]<nums.size()&&i!=nums[i]&&nums[i]!=nums[nums[i]]) {
                swap(nums[i],nums[nums[i]]);
            }
        }
        
        int i = 1;
        for(; i < nums.size(); ++i) {
            if(i != nums[i]) break;  //找到missing positive number
        }
        
        return i;
    }
};