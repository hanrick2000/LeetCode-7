//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//[
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

//显然动态规划，如果不可以破坏原来的数组，我们可以用一个长n的数组a，对三角形从上直下，到第i层是，更新数组a[j]表示，到达triangle[i][j]的最小值。
//但题目没有要求保留数组，我们可以直接在triangle数组上记录。唯一注意的是数组越界问题。

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for(int i = 1; i < triangle.size(); ++i) {
            triangle[i][0] += triangle[i-1][0];
            for(int j = 1; j < triangle[i].size()-1; ++j) {
                triangle[i][j]+= min(triangle[i-1][j-1], triangle[i-1][j]);
            }
            triangle[i].back() += triangle[i-1].back();
        }
        
        int mini = INT_MAX;
        for(int i = 0; i < triangle.back().size(); ++i) {
            mini = min(mini,triangle.back()[i]);
        }
        
        return mini;
    }
};
