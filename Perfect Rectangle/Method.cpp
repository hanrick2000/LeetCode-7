//Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.
//
//Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).
//
//
//Example 1:
//
//rectangles = [
//  [1,1,3,3],
//  [3,1,4,2],
//  [3,2,4,4],
//  [1,3,2,4],
//  [2,3,3,4]
//]
//
//Return true. All 5 rectangles together form an exact cover of a rectangular region.
//
//Example 2:
//
//rectangles = [
//  [1,1,2,3],
//  [1,3,2,4],
//  [3,1,4,2],
//  [3,2,4,4]
//]
//
//Return false. Because there is a gap between the two rectangular regions.
//
//Example 3:
//
//rectangles = [
//  [1,1,3,3],
//  [3,1,4,2],
//  [1,3,2,4],
//  [3,2,4,4]
//]
//
//Return false. Because there is a gap in the top center.
//
//Example 4:
//
//rectangles = [
//  [1,1,3,3],
//  [3,1,4,2],
//  [1,3,2,4],
//  [2,2,4,4]
//]
//
//Return false. Because two of the rectangles overlap with each other.

//长方形相交的点共有几种情况，四个点相交，三个点相交，两个点相交和一个点相交，用一个hashset保存这些点的出现情况，遇见一次如果set里没有就添加，有的话去掉，所以最后剩下来的肯定是三个点相交和一个点相交的点，看看它们是不是4个，并且面积是不是等于相加和。(防止有两个矩形一模一样重合，剩下一个矩形这种情况骗过)
//注意这里自定义hash函数，为了让unordered_set支持pair<int,int>的模板

class Solution {
public:
    struct myHash   
    {  
        size_t operator()(pair<int, int> __val) const  
        {  
            return static_cast<size_t>(__val.first * 101 + __val.second);  
        }  
    };
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        unordered_set<pair<int,int>,myHash> myset;
        
        int res = 0;
        
        for(int i = 0; i < rectangles.size(); ++i) {
            
            pair<int,int> x1 = {rectangles[i][0], rectangles[i][1]},\
            x2 = {rectangles[i][0], rectangles[i][3]},\
            x3 = {rectangles[i][2], rectangles[i][1]},\
            x4 = {rectangles[i][2], rectangles[i][3]};
            
            res += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
      
            if(myset.find(x1)== myset.end()) {
                myset.insert(x1);
            }else {
                myset.erase(x1);
            }
            
            if(myset.find(x2)== myset.end()) {
                myset.insert(x2);
            }else {
                myset.erase(x2);
            }
            
            if(myset.find(x3)== myset.end()) {
                myset.insert(x3);
            }else {
                myset.erase(x3);
            }
            
            if(myset.find(x4)== myset.end()) {
                myset.insert(x4);
            }else {
                myset.erase(x4);
            }
        }
        
        if(myset.size()!=4) return false;
        

        int y1=INT_MAX  , y2 = INT_MIN, x1 = INT_MAX, x2 = INT_MIN;
        
        for(auto x: myset) {
            
            
            y1 = min(y1,x.second);
            y2 = max(y2,x.second);
            x1 = min(x1,x.first);
            x2 = max(x2,x.first);
        }
        return (y2-y1)*(x2-x1) == res;
        
    }
};