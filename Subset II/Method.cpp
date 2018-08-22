//Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//For example,
//If nums = [1,2,2], a solution is:
//
//[
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
//]

关键就是要在dfs函数中找到去重的办法。  比如  1，2，2，2中， 遇到像2一样的数，我们可以先顺序扫描2的个数，在这三个2中，我们最多只能有4种可能，0个2，1个2，2个2，3个2. 这可以通过1个循环搞定递归，无论哪种情况递归时 都要将depth跳跃3格，进入下一个数。



class Solution {
public:

    void dfs(int depth, vector<int>& nums, vector<vector<int>> &res, vector<int> &cur) {
        
        if(depth == nums.size()) {

            res.push_back(cur);
            return;
        }
        
        int count = 1;
        for(int i = depth+1; i < nums.size(); ++i) {
            if(nums[i] == nums[depth]) {
                ++count;
            }
            else {
                break;
            }
        }
        
        
        for(int i = depth; i <= count+depth; ++i) {
            
            dfs(depth+count, nums,res,cur);
            cur.push_back(nums[i]);
            
        }
        
        for(int i = 0; i <= count; ++i) {    //回溯  恢复现场
            cur.pop_back();
        }
        
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        vector<int> cur;
        
        dfs(0, nums, res, cur);
        
        return res;
        
    }
    
    上面那种方法太傻比了，应该使用这个递归比较方便。
    void dfs(vector<int> &nums, int depth, vector<int> &cur, vector<vector<int>> &res) {
        res.push_back(cur);
        
        for(int i = depth; i < nums.size(); ++i) {
            if(i > depth && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            dfs(nums, i+1, cur, res);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        
        dfs(nums, 0, cur, res);
        return res;
    }
};