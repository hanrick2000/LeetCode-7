//这题如果排一下序，可以剪枝。如果我们排序，我们知道 当搜索找到一个解 或者和超出范围时，下一层的搜索不可能有解。 我们可以停止当前搜索。  这样可以更省时间。最坏指数级别的时间复杂度。因此排序都不是事儿。
//dfs题 配合画一下深搜树还是比较直观明了的。

class Solution {
public:

    bool dfs(vector<int>& candidates, int target, int depth, vector<int>& cur,vector<vector<int>> &res) {  //true表示可以对弟弟子树剪枝
        
        if(!target) {
            res.push_back(cur);
            return true;
        }
        
        if(target < 0) return true;
        
        for(int i = depth; i < candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            if(dfs(candidates, target-candidates[i], i, cur, res)) {
                // break;
                cur.pop_back();
                break;
            }
            cur.pop_back();
        }
        return false;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates, target, 0, cur, res);
        
        return res;
    }
};