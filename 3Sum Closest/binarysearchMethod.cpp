//本方法运用了二分查找找到最接近的值，二分查找最后那一个值的前后两值都可能是最接近的值。
class Solution {
public:

    int binarySearchClosest(vector<int>& nums, int start, int target) {
        
        int p = start, q = nums.size()-1,c;
        while(p < q) {
            c = (q-p)/2+p;
            if(nums[c] == target) return target;
            else if(nums[c] < target) p = c+1;
            else q = c-1;
        }
        c = nums[p];
        
        if(p-1>=start) {
            c = abs(nums[p-1]-target) < abs(nums[p]-target)?nums[p-1]:nums[p];
        }
        
        if(p+1<nums.size()) {
            c = abs(nums[p+1]-target) < abs(c-target)?nums[p+1]:c;
        }
        
        return c;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {

        if(nums.size()<3) return {};
        
        
        sort(nums.begin(),nums.end());
        int min = abs(nums[0]+nums[1]+nums[2]-target)+1;  //定义一个足够大的初始值
        int res;
        
        for(int i = 0; i < nums.size()-2; ++i) {
            if(i && nums[i] == nums[i-1]) continue; 
            
            for(int j = i+1; j < nums.size()-1; ++j) {
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int temp = binarySearchClosest(nums,j+1,target-nums[j]-nums[i]); 
                if(abs(nums[j]+nums[i]+temp-target)<min) {
                    res = nums[j]+nums[i]+temp;
                    min = abs(res-target);
                }
                
                
                if(!min) return res;
            }
        }

        return res;
        
    }
};