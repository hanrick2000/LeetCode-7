//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

//这题其实思路很简单，给定一个点，求所有点到它的斜率，斜率相同的肯定在一条线上。O（n^2)

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        
        int res = 0;
        
        for(auto p1: points) {
            int maxi = 0, vertical = 0, same=0;
            
            unordered_map<double,int> slope;
            
            for(auto p2: points) {
                
                if(p1.x == p2.x && p1.y == p2.y)  {
                    
                    ++same;
                }
                else if (p1.x == p2.x){

                    maxi = max(maxi, ++vertical);
                }
                else {
                    double s = (p1.y - p2.y)*1.0/(p1.x - p2.x);

                    maxi = max(maxi, ++slope[s]);
                }
            }      
            maxi+=same;
            res = max(maxi,res);
        }
        
        return res;

    }
};