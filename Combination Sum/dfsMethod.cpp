//标准的dfs。每一个dfs 函数的调用都对应了一个搜索状态。 如果target ==0 或 <0 都可以不用说，很简单。
//正常的流畅我们总要到下一层去搜索。能尽兴下一步搜索的状态有depth 到 candidate的尾部。
//另外这道题他说candidates没有重复数字，因此可以直接进行dfs. 不会有重复发生。

class Solution {
public:
    void dfs(vector<int>& candidates, int target, int depth, vector<int>& cur,vector<vector<int>> &res) {
        
        if(target == 0) {
            res.push_back(cur);
            return;
        }
        
        if(target < 0) return;
        
        for(int i = depth; i < candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i, cur, res);
            cur.pop_back();
        ｝
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
//        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates, target, 0, cur, res);
        
        return res;
    }
};