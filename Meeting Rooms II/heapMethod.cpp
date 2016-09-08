//这题这个解法还是不错的，首先按照start升序排，然后其实我们要做的就是遍历每一个会议，按照该会议的end，然后如果该start比之前最早的end要晚，那么这个会议就可以放在那个最早end的会议室后面，从而会议室数目不变，而最早end的那个会议可以取消了，否则表明该start要比之前那个最早的end都要早，则之前的所有会议start都要更早，表明这段时间的会议都会重叠，所以会议室数要++。所以可以对end用heap实现。而且发现heap只进不减，heap最后的size就是所需会议室的size

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
    
    static bool compare(const Interval& a, const Interval& b) {
        
        return a.start < b.start;
        
    }
    

    int minMeetingRooms(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), compare);
        
        priority_queue<int,vector<int>, greater<int>> myheap;
        
        
        for(int i = 0; i < intervals.size(); ++i) {
            
            if(myheap.size()&&myheap.top() <= intervals[i].start) {
                myheap.pop();
            }

            myheap.push(intervals[i].end);
        }
        
        return myheap.size();
    }
};