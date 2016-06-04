//用了i,j两重循环，然后用2sum的方法。
//时间O(n^3)

class Solution {
public:
    
    void twoSum(vector<int>& nums, int start, int target, int first, int second, vector<vector<int>> & res) {
        int p = start, q = nums.size()-1,temp;
        while(p < q) {
            temp = nums[p] + nums[q];
            if(temp < target) p++;
            else if (temp > target) q--;
            else {
                res.push_back({first, second, nums[p], nums[q]});
                do{ 
                    p++;
                }while(nums[p] == nums[p-1]&&p<q);
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if(nums.size()<4) return {};
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        
        for(int i = 0; i < nums.size()-1;++i) {
            if(i&&nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < nums.size()-2; ++j) {
                if(j > i+1&&nums[j] == nums[j-1]) continue;
                twoSum(nums,j+1,target-nums[i]-nums[j],nums[i],nums[j], res);
            }
        }
        
        return res;
    }
};