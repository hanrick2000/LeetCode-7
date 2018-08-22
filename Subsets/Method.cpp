//Given a set of distinct integers, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//For example,
//If nums = [1,2,3], a solution is:
//
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//]


显然dfs, 每一层所做的决定只可能两种，选nums[depth]或不选。

class Solution {
public:

    void dfs(vector<vector<int>> &res, vector<int> &cur, int depth, vector<int>& nums) {
        if(depth == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        cur.push_back(nums[depth]);
        dfs(res, cur, depth+1, nums);
        cur.pop_back();
        dfs(res, cur, depth+1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        
        dfs(res, cur, 0, nums);
        
        return res;
    }
    
    还可以这种递归：
class Solution {
public:
    void dfs(vector<int> &nums, vector<int> &cur, vector<vector<int>>&res, int depth) {
        res.push_back(cur);
        for(int i = depth; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums,cur,res,i+1);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, cur, res, 0);
        return res;
    }
};
};
