//Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//For example,
//Given [10, 9, 2, 5, 3, 7, 101, 18],
//The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
//
//Your algorithm should run in O(n2) complexity.
//
//Follow up: Could you improve it to O(n log n) time complexity?

这是dp算法，很简单，每一次保存下第nums[i]的值 然后求得时候依次比较前面的大小，如果大，就1+nums[i]. O(n^2)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        
        vector<int> dp(nums.size(),1);

        int globalMax = 1;
        for(int i = 1; i < nums.size(); ++i) {
            int maxi = 1;
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    maxi = max(maxi, dp[j]+1);
                    
                }
            }
            dp[i] = maxi;
            globalMax = max(dp[i], globalMax);
        }
        
        return globalMax;
        
    }
};

//还有一个NB的二分做法。
//d[k] 表示   扫描到当前i时， LIS序列长度为k 的最小nums[j]  0<=j <i
//    按dp[t]=k来分类，只需保留dp[t]=k的所有a[t]中的最小值，设d[k]记录这个值，d[k]=min{a[t],dp[t]=k}。
//    这时注意到d的两个特点（重要）：
//1. d[k]在计算过程中单调不升；           
//2. d数组是有序的，d[1]<d[2]<..d[n]。
//    利用这两个性质，可以很方便的求解：
//1. 设当前已求出的最长上升子序列的长度为len（初始时为1），每次读入一个新元素x：
//2. 若x>d[len]，则直接加入到d的末尾，且len++；（利用性质2）
//   否则，在d中二分查找，找到第一个比x小的数d[k]，并d[k+1]=x，在这里x<=d[k+1]一定成立（性质1,2）。
// 最后返回d的长度就可以了

class Solution {
public:


    void binarySearch(vector<int>& d,int start,int target) {
        int a = start, b = d.size()-1;
        
        while(a <= b) {
            int c = (a+b)/2;
            if(d[c] == target ) {
                return;
            }
            
            if(d[c] < target) {
                a = c+1;
            }
            
            else {
                b = c-1;
            }
            
        }
        
        d[a] = target;
    }


    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        
        vector<int> d;   //d[k] 表示   扫描到当前i时， LIS序列长度为k 的最小nums[j]  0<=j <i
        
        d.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i]>d.back()) {
                d.push_back(nums[i]);
            }
            
            else if(nums[i]<d.back()) {
                binarySearch(d,0,nums[i]);
            }
        }
            
        return d.size();
        
    }
};