//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

很简单的一道题，记录每一个断点的开始位置和结束位置，结束位置通过nusm[i]!=nums[i+1]来判断。最后不要忘记有可能会漏下最后一个区间，所以可以在nums后面加上一个数。

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(!nums.size()) return {};
        nums.push_back(nums.back()+2);  //可能会溢出，但不影响结果，
        
        int pre = nums[0];
        
        vector<string> res;
        
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[i-1]+1) {
                // res.push_back();
                
                if(pre == nums[i-1]) {
                    res.push_back(to_string(pre));
                }
                else {
                    res.push_back(to_string(pre) + "->" + to_string(nums[i-1]));
                }
                pre = nums[i];
                
            }
        }
        return res;
    }
};