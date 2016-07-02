//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//Given [1,3],[2,6],[8,10],[15,18],
//return [1,6],[8,10],[15,18].


这题按照区间的起点排序，然后顺序扫描，如果能够接起来，就延长，否则重新开始一个start。

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    
    
    static bool cmp(const Interval& a, const Interval& b) {
        
        return a.start<b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int start = intervals[0].start,  maxi = intervals[0].end;
        
        vector<Interval> res;
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start<=maxi) {
                maxi = max(intervals[i].end,maxi);
            }
            
            else {
                res.push_back(Interval(start,maxi));
                start = intervals[i].start;
                maxi = intervals[i].end;
                --i;   // 这个i是用来判断找到了最长延展壮腰，--i表示下次循环还要判断该区间。
            }
        }
        res.push_back(Interval(start,maxi)); // 得把最后的区间加进去
        
        
        return res;
        
    }
};