//A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
//
//For example, given three people living at (0,0), (0,4), and (2,2):
//
//1 - 0 - 0 - 0 - 1
//|   |   |   |   |
//0 - 0 - 0 - 0 - 0
//|   |   |   |   |
//0 - 0 - 1 - 0 - 0
//The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
//
//Hint:
//
//Try to solve it in one dimension first. How can this solution apply to the two dimension case?


//一维情形：距离所有点最近的点在中位数上，所以求距离之和可以从两端开始求差，相加，二维可以横纵分开。最后纵横相加即可。


class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        
        if(!grid.size() || !grid[0].size()) return 0;
        
        int res = 0;
        
        vector<int> row, colum;
        
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j]) {
                    row.push_back(i);
                    colum.push_back(j);
                }
            }
        }

        sort(colum.begin(), colum.end());
        
        int p = 0, q = row.size()-1;
        
        while(p<q) {
            res += row[q--] - row[p++];
        }
        
        p = 0, q = colum.size()-1;
        
        while(p<q) {
            res += colum[q--] - colum[p++];
        }
        
        return res;
    }
};