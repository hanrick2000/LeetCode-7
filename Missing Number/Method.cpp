//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//
//For example,
//Given nums = [0, 1, 3] return 2.
//
//Note:
//Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

只想到这么一个方法，0-n全部加起来，再减掉所有数。但是会溢出，得用long long.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = nums.size()*(1+nums.size())/2;
        
        for(auto x: nums) {
            sum-=x;
        }
        
        return sum;
    
    }
};

//这个方法是生搬硬套，强行数一下0...n每一位bit一共出现了多少次，然后再遍历一边数组，减掉

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int numberof1[32];
        
        memset(numberof1,0,sizeof(numberof1));
        
        for(int i = 1; i <= nums.size(); ++i) {
            
            int tmp = i;
            for(int j = 0; j < 32; ++j) {
                
                if(!tmp) {
                    break;
                }
                if(tmp&1) ++numberof1[j];
                tmp>>=1;
            }
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i];
            for(int j = 0; j < 32; ++j) {
                
                if(!tmp) {
                    break;
                }
                if(tmp&1) --numberof1[j];
                tmp>>=1;
            }
        }
        
        int res = 0;
        
        for(int i = 31; i >-1; --i) {
            res = res<<1;
            if(numberof1[i]) {
                ++res;
            }
        }
        
        return res;
        
    }
    
    和single number很像
    
    int missingNumber(vector<int>& nums) {
        
        int res = 0;
        
        for(int i = 0; i <= nums.size(); ++i) res^=i;
        for(int &num: nums) res^=num;
        
        return res;

    }
};