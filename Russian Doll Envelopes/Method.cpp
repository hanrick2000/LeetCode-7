//You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
//
//What is the maximum number of envelopes can you Russian doll? (put one inside other)
//
//Example:
//Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

//这题有点像找最长递增子序列一样，不过我们得把这些信封按照长从小到大排列.我们可以发现，所有可能被包的小信封都排在前面了，所以后面要做的就是验证它们真的能被包囊。

bool isLarger(const pair<int,int> &a, const pair<int,int> &b) {
    
    return a.first > b.first && a.second > b.second;    
}

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& arr) {
            
        sort(arr.begin(), arr.end());
        
        int res = 0;
        vector<int> dp(arr.size(),1);
        
        for (int i = 0; i < arr.size(); ++i) {
            
            for(int j = i-1; j >= 0; --j) if(isLarger(arr[i], arr[j]))  dp[i] = max(dp[i], dp[j]+1);
            
            res = max(res, dp[i]);
        }
        
        return res;

    }
};