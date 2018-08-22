//Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.
//
//For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.
//
//Note:
//You may assume the interval's end point is always bigger than its start point.
//You may assume none of these intervals have the same start point.
//Example 1:
//Input: [ [1,2] ]
//
//Output: [-1]
//
//Explanation: There is only one interval in the collection, so it outputs -1.
//Example 2:
//Input: [ [3,4], [2,3], [1,2] ]
//
//Output: [-1, 0, 1]
//
//Explanation: There is no satisfied "right" interval for [3,4].
//For [2,3], the interval [3,4] has minimum-"right" start point;
//For [1,2], the interval [2,3] has minimum-"right" start point.
//Example 3:
//Input: [ [1,4], [2,3], [3,4] ]
//
//Output: [-1, 2, -1]
//
//Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
//For [2,3], the interval [3,4] has minimum-"right" start point.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

这题就是找到每一个start正好>= 本iterval.end的interval下标。首先要排序，不过排序时得包含之前的index，新造一个节点。
二分查找找到第一个start >= end
 
struct Node {
    Interval inter;
    int index;
    Node(): inter(), index(0) {}
    Node(int s, int e, int i): inter(s, e), index(i) {}
};

bool cmp(const Node& i1, const Node& i2) {
    return i1.inter.start < i2.inter.start;
}

class Solution {
public:

    int search(vector<Node>& nodes, int end) {   //查找第一个 start >= end
        int p = 0, q = int(nodes.size())-1;
        
        while (p < q) {
            int c = (q - p)/2 + p;
            if(nodes[c].inter.start >= end) q = c;
            else p = c + 1;
        }
        
        if(p == nodes.size() || nodes[p].inter.start < end) return -1;
        return nodes[p].index;
    }
    
    vector<int> findRightInterval(vector<Interval>& intervals) {
        
        vector<Node> nodes(intervals.size());
        for(int i = 0; i < intervals.size(); ++i) {
            nodes[i] = Node(intervals[i].start, intervals[i].end, i);
        }
        
        sort(nodes.begin(), nodes.end(), cmp);
        vector<int> res(intervals.size());
        for(int i = 0; i < intervals.size(); ++i) {
            res[i] = search(nodes, intervals[i].end);
        }
        return res;    
    }
};