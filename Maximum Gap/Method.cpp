//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
//Try to solve it in linear time/space.
//
//Return 0 if the array contains less than 2 elements.
//
//You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

//这题如果要用O(n)时间空间，可以用桶排序的方法。我们先求出数组里面的最大值b最小值a. 我们可以想象，如果总共有N个数，那么maximum gap 最小也至少有 len =  (b-a)/(N-1)上整。比如(0,10)  N=4. 这样我们可以把这段区间划分为一个一个桶。我们把每一个桶的大小也正好调整成这个数. 第一个桶的范围是 [a, a+len-1] 第二个桶的范围是 [a+len, a+2*len-1] ... 共需多少bucket? (b-a)/len +1 ... 不过这个数不会比N大。 反证：  假设 (b-a)/len +1 > n 即 >=n+1 (b-a)/len >=N (b-a)>= len*N   那么len*N/(N-1)上整至少是len+1, 就与len矛盾了。所以我们 bucket数组就可以简单的开辟N个。

//然后呢，我们遍历数组一遍，把每一个数按照bucket的范围放入相应的bucket里。注意到同一个bucket里两数差最多是 len-1, 所以maximum gap一定出现在相邻的两个gap。即 下一个gap.min - 该gap.max.  所以我们每一次遍历数时只要维护该bucket的最大最小值即可。

class bucket {
public:
    int max;
    int min;
    
    bool valid;
    bucket():valid(false){};
};


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        if(nums.size()<2) return 0;
        
        int mini = nums[0], maxi = nums[0];
        
        for(int i = 0; i < nums.size(); ++i) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        
        if(mini==maxi) return 0;   //这一步太容易漏了，否则 就会用0个bucket.
        
        int len = (maxi - mini)/(nums.size()-1);
        if((maxi - mini)%(nums.size()-1)) ++len;
        
        vector<bucket> a(nums.size(),bucket());
        
        for(int i = 0; i < nums.size(); ++i) {
            int offset = (nums[i]-mini)/len;
            
            if(!a[offset].valid) {
                a[offset].max = nums[i];
                a[offset].min = nums[i];
                a[offset].valid = true;
            }
            
            else {
                a[offset].max = max(a[offset].max,nums[i]);
                a[offset].min = min(a[offset].min,nums[i]);
            }
        }
        
        int pre = a[0].max, res = 0;
        
        for(int i = 1; i < nums.size(); ++i) {
            if(a[i].valid) {
                res = max(a[i].min - pre,res);
                pre = a[i].max;
            }
        }
        
        return res;
    }
};