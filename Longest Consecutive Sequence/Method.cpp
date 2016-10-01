//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//For example,
//Given [100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//
//Your algorithm should run in O(n) complexity.

这题思路：先用hashset把出现过的数全部记录下来。然后第二遍扫描数组，对每一个数，往两边查询n-1,n-2...   ,n+1 n+2是不是出现过，比如 看到4，我们查询3,2,5,6等等是否存在。没查询到一个数，记得从hashset里面删掉，因为包括4的连续串和包括3开始的连续串其实是同一个，不用重复计算，所以复杂度O(n).

class Solution {
public:
    
    int consecutiveLength(int start, unordered_set<int> &mymap, int dir) {
        
        int len = 0;
        
        while(mymap.find(start)!=mymap.end()) {
            ++len;
            mymap.erase(start);
            start+=dir;
        }
        
        return len;
    }
    

    int longestConsecutive(vector<int>& nums) {
        
        int rst = 0;
        
        unordered_set<int> myset;
        for(int i = 0; i < nums.size(); ++i) {
            myset.insert(nums[i]);
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            
            rst = max(rst, consecutiveLength(nums[i], myset, 1) + consecutiveLength(nums[i]-1, myset, -1));
        }
        
        return rst;
    }
};