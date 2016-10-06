//Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.
//
//For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
//
//[1, 1]
//[1, 1], [3, 3]
//[1, 1], [3, 3], [7, 7]
//[1, 3], [7, 7]
//[1, 3], [6, 7]
//Follow up:
//What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?


    /**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//每一次找到interval 之间的lower bound. 然后分情况讨论。
 
class SummaryRanges {
    
    vector<Interval> intervals;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {

        int p = 0, q = int(intervals.size())-1;
        
        while(p < q) {
            int c = (q - p)/2 + p;
            
            if(intervals[c].start < val) p = c + 1;
            else q = c;
        }
                
        if(p < intervals.size()&& intervals[p].start<val)  p = p+1;

        if(p&&intervals[p-1].end >= val) return;
        
        if(p < intervals.size() && intervals[p].start == val) return;
        
        if(p && intervals[p-1].end == val-1 && p < intervals.size() && intervals[p].start == val+1) {
            intervals[p-1].end = intervals[p].end;
            intervals.erase(intervals.begin()+p);
            return;
        }
        if(p && intervals[p-1].end == val-1) {
            intervals[p-1].end = val;
            return;
        }
        
        if(p < intervals.size() && intervals[p].start == val+1) {
            intervals[p].start = val;
            return;
        }
      
        intervals.insert(intervals.begin()+p, Interval(val,val));

        return;        
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */