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


注意这题j不用从0开始迭代，j可以从i+1开始迭代。因为a到b的斜率算过我们不用再算b到a的斜率。 注意vertical得当成hash的一项，只不过
是正无穷，就得另外算。same的点也得算，到时候求最大时加上去。
    int maxPoints(vector<Point>& points) {    
        int res = 0;

        for(int i = 0; i < points.size(); ++i) {
            
            unordered_map<double,int> slope;
            int verti = 0, same = 0;
            
            for(int j = i+1; j < points.size(); ++j) {
                if(points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++same;
                } else if(points[i].x == points[j].x) {
                    ++verti;
                } else {
                    double s = 1.0*(points[i].y - points[j].y)/(points[i].x - points[j].x);
                    ++slope[s];
                }
            }
            int t = 0;
            for(auto &x: slope) t = max(t, x.second);
            t = max(t, verti);
            res = max(res, t+same+1);
        }
        return res;
    }