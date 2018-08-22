//Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.
//
//For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

很容易出bug的一道题，基本思路是，两个两个将相邻的vector的数字产生他们之间的区间.注意要考虑到lower和upper。同时还要考虑如果第一个数大于lower 还得考虑lower到第一个数之间的区间，如果最后一个数小于upper还得考虑这个数到upper之间的区间，同时还得考虑空vector。

class Solution {
public:

    string returnInterval(int a, int b, int lower, int upper) {
        
        int small = max(a+1,lower);
        int large = min(b-1,upper);
        if(small < large) return to_string(small)+ "->" + to_string(large);
        
        if(small==large) return to_string(small);
        
        return "";
        
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        if(!nums.size()) {
            if(lower == upper)
                return {to_string(lower)};
            return {to_string(lower)+ "->" + to_string(upper)};
        }

        vector<string> res;
        

        if(nums[0]>lower) {
            string tmp = returnInterval(lower-1,nums[0],lower,upper);
            if(tmp!="") res.push_back(tmp);
        }
        
        for(int i = 0; i < nums.size()-1; ++i) {
            string tmp = returnInterval(nums[i],nums[i+1],lower,upper);
            if(tmp!="") res.push_back(tmp);
        }
        
        if(nums.back()<upper) {
            string tmp = returnInterval(nums.back(),upper+1,lower,upper);
            if(tmp!="") res.push_back(tmp);
        }
        
        return res;
    }
    
    string merge(long long lower, long long upper, long long a, long long b) {
        ++a;
        --b;
        if(a > b) return "";
        
        int left = max(a, lower);
        int right = min(b, upper);
        
        if(left > right) return "";
        if(left == right) return to_string(left);
        return to_string(left) + "->" + to_string(right);
        
    }
    

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        
        if(nums.size() && nums[0] > lower || nums.empty()) {
            nums.insert(nums.begin(), lower-1);
        }
        
        if(nums.size()&& nums[0] < upper || nums.empty()) {
            nums.push_back(upper+1);
        }
        
        for(int i = 0; i < nums.size()-1; ++i) {
            string tmp = merge(lower, upper, nums[i], nums[i+1]);
            if(tmp!="") res.push_back(tmp);
        }
        
        return res;
    }
};