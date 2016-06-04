// 该方法运用了2sum的做法，具体是：用i遍历一遍数组，对剩下的那些数用2sum的方法找。  同时此2sum要找到全部的值，并且不能重复，要适当做一些修改。如果找到一组解，移动指针p++, 停留在第一个使得nums[p]与nums[p-1]不同的位置，继续找。

//时间O(n^2).

class Solution {
public:

     void twoSum(vector<int>& nums, int start, int target, vector<vector<int>> &res) {
        int p = start, q = nums.size()-1,temp;
        while(p < q) {
            temp = nums[p] + nums[q];
            if(temp < target) p++;
            else if (temp > target) q--;
            else {
                res.push_back({-temp,nums[p],nums[q]});
                do{ 
                    p++;
                }while(nums[p] == nums[p-1]&&p<q);
            }
        }
    }
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size()<3) return {};
        
        vector<vector<int>> res;

        sort(nums.begin(),nums.end());
        
        for(int i = 0; nums[i]<=0; ++i) {
            if(i && nums[i] == nums[i-1]) continue; 
            twoSum(nums,i+1,-nums[i],res);
        }
        
        return res;
    }
};