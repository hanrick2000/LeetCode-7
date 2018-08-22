//Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
//
//For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].


//可以先倒序排序，然后把1，2交换，3，4交换。。。

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        for(int i = 0; i+1 < nums.size(); i+=2) {
            swap(nums[i],nums[i+1]);
        }
    }
};

//有一个更吊的O(n)做法，题目要求是如果i是奇数那么nums[i]>=nums[i+1],偶数nums[i]<=nums[i+1]. 那么我们可以对每一个i，比较nums[i]与nums[i+1].发现不符合规则就swap(nums[i]和nums[i+1]).这样线性扫描每一个i即可。
//为什么这个会正确呢？会不会出现a,b,c 发现a,b不满足交换变成 b,a,c  发现a,c不满足，然后交换c,a. 变成b,c,a 那么b,c会不会又不满足呢？
//分类讨论，如果a下标是偶数，  那么a,b交换是因为 a > b. 所以变成b,a, 交换a,c现在是因为a<c. 所以变成 b,c,a 发现 b < c 依然正确。同理如果a下标是偶数也可以证明。代码如下

    void wiggleSort(vector<int>& nums) {
        
        for(int i = 0; i < int(nums.size())-1; ++i) {
            if(i&1 &&(nums[i] < nums[i+1]) || !(i&1) && (nums[i] > nums[i+1])) swap(nums[i], nums[i+1]);
        }
        
    }