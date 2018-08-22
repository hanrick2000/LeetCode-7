//Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
//Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
//Example 2:
//Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
//
//This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

//这题思路不难，但是要用简介的代码的写出来 我们可以用下面的思路。
//
//1) 先从头在intervals[i]中找出与newinterval 满足intervals[i].end >= newInterval.start。 这个intervals[i] 是第一个可能与new interval相交的区间，如果这个interval 没有和newinterval相交，那么直接在i位置插入new interval即可。 否则进行第二步，找到重合的最后一个区间
//2) 进行到这一步表明至少有一个区间会和new interval 重合，所以我们从后面扫描可以直接找出最后一个重叠的区间。
//3) 找到头和尾后，做两次merge interval 即可，第一次merge 头和new interval,第二次尾和 new interval，merge要修改newinterval。
//时间O(n), 空间O(n).



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

    bool isOverlapped(Interval& a, Interval& b) {
        if(b.start < a.start){
            return b.end>=a.start;
        }
        
        else return a.end>=b.start;
    }
    
    void merge(Interval& a, Interval& b) {
        
        b.start = min(a.start, b.start);
        b.end = max(a.end, b.end);
        
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
        vector<Interval> res;
        int first = intervals.size(), last = -1;
        
        for(int i = 0; i < intervals.size(); ++i) {
            if(intervals[i].end >= newInterval.start) {
                first = i;
                break;
            }
        }
        
        if(first == intervals.size() || newInterval.end < intervals[first].start) {
            intervals.insert(intervals.begin()+first,newInterval);
            return intervals;   //没有与new interval, 所以直接在first位置插入即可
        }
        
        for(int i = intervals.size() - 1; i >= 0; --i) {
            if(isOverlapped(intervals[i],newInterval)) {
                last = i;
                break;
            }
        }
        
        merge(intervals[first] , newInterval);
        merge(intervals[last] , newInterval);
        
        for(int i = 0; i < first; ++i) res.push_back(intervals[i]); 
        res.push_back(newInterval);
        
        for(int i = last+1; i < intervals.size(); ++i) res.push_back(intervals[i]);
                
        return res;

    }
    
    网上一个很好的代码。找到interval中第一个和最后一个与newinterval重复的下标，然后merge删除或者插入。
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto lb = std::lower_bound(intervals.begin(), intervals.end(), newInterval,
            [](const Interval& lhs, const Interval& rhs) {
                return lhs.end < rhs.start;
            });
            
        auto ub = std::upper_bound(lb, intervals.end(), newInterval,
            [](const Interval& lhs, const Interval& rhs) {
                return lhs.end < rhs.start;
            });
            
        if (lb == ub) {
            intervals.insert(lb, newInterval);
        } else {
            lb->start = std::min(lb->start, newInterval.start);
            lb->end = std::max((ub-1)->end, newInterval.end);
            intervals.erase(lb+1, ub);
        }
        return intervals;
    }
    
    自己又写了一个O（n)的算法。
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

        bool flag = true;
        vector<Interval> res;
        
        for(auto &interval: intervals) {
            if(interval.end < newInterval.start) res.push_back(interval);
            else if(interval.start > newInterval.end) {
                if(flag) {
                    res.push_back(newInterval);
                    flag = false;
                }
                res.push_back(interval);
            }
            else {
                newInterval.start = min(newInterval.start, interval.start);
                newInterval.end = max(newInterval.end, interval.end);
            }
        }

        if(flag) {
            res.push_back(newInterval);
        }
        return res;
    }
};