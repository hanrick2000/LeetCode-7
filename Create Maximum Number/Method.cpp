//Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.
//
//Example 1:
//nums1 = [3, 4, 6, 5]
//nums2 = [9, 1, 2, 5, 8, 3]
//k = 5
//return [9, 8, 6, 5, 3]
//
//Example 2:
//nums1 = [6, 7]
//nums2 = [6, 0, 4]
//k = 5
//return [6, 7, 6, 0, 4]
//
//Example 3:
//nums1 = [3, 9]
//nums2 = [8, 9]
//k = 3
//return [9, 8, 9]

这题分为三步
//1） 给一个数组，求出k个数字能组成的最大值。我们需要用栈，遍历数组，每一次当发现数组元素大于栈顶元素时，pop,直到发现栈空或者栈顶元素大等于于栈顶元素或者弹出栈顶后栈里的元素+数组剩下的元素依然大于等于k.最后栈里保存的就是结果
//2) 两个数组， 对每一个数组求i个数字的最大值，另一个求k-i.将两个结果merge起来。merge方法是从头数起，一次选大的那个移动指针，如果遇到相同的，要一直往后比，直到一个数组的元素大于另一个数组，或者逼到最后一个数组还有长度，添加这个数组的元素。
//3） 最后第二部结果的最大值。

class Solution {
public:

    vector<int> maxNumberHelepr(vector<int>& nums, int k) {
        
        vector<int> mystack;
        int len = min(k,int(nums.size()));
        
        for(int i = 0; i < nums.size(); ++i) {
            
            if((mystack.empty() || mystack.back() >= nums[i]) && mystack.size() < k) mystack.push_back(nums[i]);
            
            else {
                
                while(mystack.size() && mystack.back() < nums[i] && mystack.size()-1 + nums.size() - i  >= len) {
                    mystack.pop_back();
                }
                
                if(mystack.size() < k) mystack.push_back(nums[i]);//这个if条件太容易遗忘了
            }
        }

        return mystack;
    }
    
    vector<int> merge(vector<int>& a, vector<int> &b) {
        
        vector<int> c;
        int p = 0, q = 0;
        
        while(p < a.size() && q < b.size()) {
            
            if(a[p] > b[q]) {
                c.push_back(a[p++]);
            }
            
            else if(a[p] < b[q]) {
                c.push_back(b[q++]);
            }

            else {
                int i = p+1, j = q+1;
                for(; i < a.size()&&j<b.size(); ++i,++j) {
                    
                    if(a[i] > b[j]) {
                        c.push_back(a[p++]);
                        break;
                    }
                    else if(a[i] < b[j]) {
                        c.push_back(b[q++]);
                        break;
                    }
                }
                
                if(i == a.size()) {
                    c.push_back(b[q++]);
                }
                
                else if(j == b.size()){
                    c.push_back(a[p++]);
                }
            }
            
        }
        while(p < a.size()) {
            c.push_back(a[p++]);
        }
        
        while(q < b.size()) {
            c.push_back(b[q++]);
        }

        return c;
        
    }

    bool isGreater(vector<int> &a, vector<int> &b) {
        
        if(a.size()!=b.size()) return a.size() > b.size();
        
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] < b[i]) return false;
            if(a[i] > b[i]) return true;
        }
        return false;

    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<int> c;
        vector<int> maxi;

        for(int i = 0; i <=k ; ++i ) {
            
            if(nums1.size() < i || nums2.size() < k-i) continue;
            
            vector<int> a = maxNumberHelepr(nums1, i);
            vector<int> b = maxNumberHelepr(nums2, k-i);
            c = merge(a,b);
            
            if(isGreater(c, maxi)) maxi = c;
        }
        
        return maxi;
    }
};