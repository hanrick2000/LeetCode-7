//Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.
//
//The returned array must be in sorted order.
//
//Expected time complexity: O(n)
//
//Example:
//nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,
//
//Result: [3, 9, 15, 33]
//
//nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5
//
//Result: [-23, -5, 1, 7]


//注意想到a,b可以为0的特殊情况。  一般二次函数，先求出对称轴。然后二分查找对称轴，然后p,q从对称轴左右开始往两边进行类似于merge的操作。最后注意a<0要取反。


class Solution {
public:

    int binary_search1(vector<int>& nums, double target) {
        
        int p = 0,  q = int(nums.size())-1;
        
        while(p < q) {
            
            int c = (q - p)/2 + p;
            
            if(nums[c] <= target) p = c+1;
            
            else if (nums[c] > target) {
                q = c;
            }
        }
        
        if(nums[p] > target) return p;
        
        return p + 1;
    }

    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        
        if(!nums.size()) return {};
        
        if(a == 0) {
            if(b == 0) return vector<int> (nums.size(), c);
            vector<int> res (nums.size());

            for(int i = 0; i < nums.size(); ++i) {
                res[i] = b*nums[i] + c;
            }

            if(b < 0)  reverse(res.begin(),res.end());
            
            return res;
        }
        
        vector<int> res (nums.size());
     
        double axis = - b*1.0/(2*a);
        
        int q = binary_search1(nums, axis), p = q - 1, i = 0;
        
        while(p >= 0 && q < nums.size())  {
            
            if(axis - nums[p] < nums[q] - axis) {
                res[i++] = a*nums[p]*nums[p] + b*nums[p] + c;
                p--;
            }
            
            else {
                res[i++] = a*nums[q]*nums[q] + b*nums[q] + c;
                q++;
            }
        }
                
        while(p >= 0)  {
            
            res[i++] = a*nums[p]*nums[p] + b*nums[p] + c;
            p--;
        }
        
        while(q < nums.size())  {
            
            res[i++] = a*nums[q]*nums[q] + b*nums[q] + c;
            q++;
        }
        
        if(a < 0)  reverse(res.begin(),res.end());
        
        return res;
        
    }
};