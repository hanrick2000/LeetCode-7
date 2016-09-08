//Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
//
//For example,
//Given [[0, 30],[5, 10],[15, 20]],
//return 2.


//用一个map记录时间点i开始的会议个数，（结束的就自减）。
//然后顺序遍历这些时间线，控制一个room变量，加上这些值，出现的最高峰就是结果。



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
    

    int minMeetingRooms(vector<Interval>& intervals) {
        
        map<int, int> mymap;
        
        for(auto x: intervals) {
            ++mymap[x.start];
            --mymap[x.end];
        }
        
        int res = 0,room = 0;
        
        for(auto it = mymap.begin(); it!=mymap.end(); ++it ) {
            
            res = max(res,room+=it->second);
        }
      
        return res;
        
    }
};