//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.


摩尔投票法。这题是这样的大于[n/3]的数共有两个。本质思路是不断从数组中找到，三个不同的数，分为一组，然后剔除。最后剩下的数都有可能是candidates。 只要检验一遍即可。
那么如何实现上述思路呢？
我们可以假设第一个数是候选1，下一个不等于它的数是候选2.扫描整个数组，如果当前数等于候选1，候选1的计数++，如果等于候选2，候选2计数++，若果找到一个数不等于他俩，两个计数那就--，表明将这三个数组成一组，拿掉。如果任何一个candidaytes 变0了。那就换candidate。
最后检验一下两个candidates到底是不是。


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        if(!nums.size()) return {};
        
        vector<int> res;
        
        int candidates1 = nums[0], c1 = 1, candidates2, c2=0;
        
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i]==candidates1) {
                ++c1;
                continue;
            }
            else if(!c2) {
                candidates2 = nums[i];
                ++c2;
                continue;
            }
            if(nums[i]==candidates2) ++c2;
            
            if(nums[i] != candidates1 && nums[i] != candidates2) {
                --c1;
                if(!c1) {
                    candidates1 = nums[i];
                    c1 = 1;
                }
                --c2;
            }
        }
        
        c1 = c2 = 0;
        for(auto x: nums) {
            if(x == candidates1) ++c1;
            else if(x == candidates2) ++c2;
        }
        if(c1>nums.size()/3) res.push_back(candidates1);
        if(c2>nums.size()/3) res.push_back(candidates2);
        
        return res;
        
    }
};