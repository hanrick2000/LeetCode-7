//Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.
//
//Example 1:
//Given points = [[1,1],[-1,1]], return true.
//
//Example 2:
//Given points = [[1,1],[-1,-1]], return false.
//
//Follow up:
//Could you do better than O(n2)?
//
//Hint:
//
//Find the smallest and largest x-value for all points.
//If there is a line then it should be at y = (minX + maxX) / 2.
//For each point, make sure that it has a reflected point in the opposite side.

//找到坐标最大最小值  就可以确定对称轴的位置。然后对所有点查找对称点是否也存在即可。

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        
        int minX = INT_MAX, maxX = INT_MIN;
        
        unordered_map<int,set<int>> myset;
        
        for(auto x: points) {
            minX = min(minX, x.first);
            maxX = max(maxX, x.first);
            myset[x.first].insert(x.second);
        }
        
        double axis = (maxX-minX)/2.0 + minX;
        
        for(auto x:points) {
            if(myset.find(axis-x.first+axis)==myset.end()||myset[axis-x.first+axis].find(x.second)==myset[axis-x.first+axis].end()) return false;
        }
        
        return true;
        
    }

};