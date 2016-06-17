//Given a collection of distinct numbers, return all possible permutations.
//
//For example,
//[1,2,3] have the following permutations:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//]

//显然用dfs，所有穷尽列举的问题都可以用dfs。
//permute{1,2,3,4} = ｛1｝ + permute{2,3,4} || {2}+  permute{1,3,4} || {3} + permute{2,1,4} || {4} + permute{2,3,1}
//所以 每一次dfs求解时 可以把 当前的数 和后面的数  换一下，把这个数放进cur，然后下一步搜索

class Solution {
public:

    void dfs(int depth, vector<int>& nums,vector<int> &cur, vector<vector<int>> &res) {
        if(depth == nums.size()) res.push_back(cur);
        
        for(int i = depth; i < nums.size(); ++i) {
            swap(nums[depth],nums[i]);
        
            cur.push_back(nums[depth]);
            dfs(depth+1,nums,cur,res);
            
            cur.pop_back();
            swap(nums[depth],nums[i]);
        }
            
    }
    
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> cur;
        
        dfs(0,nums,cur,res);
        return res;    
    }
};