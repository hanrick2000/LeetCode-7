//Design a hit counter which counts the number of hits received in the past 5 minutes.
//
//Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.
//
//It is possible that several hits arrive roughly at the same time.
//
//Example:
//HitCounter counter = new HitCounter();
//
//// hit at timestamp 1.
//counter.hit(1);
//
//// hit at timestamp 2.
//counter.hit(2);
//
//// hit at timestamp 3.
//counter.hit(3);
//
//// get hits at timestamp 4, should return 3.
//counter.getHits(4);
//
//// hit at timestamp 300.
//counter.hit(300);
//
//// get hits at timestamp 300, should return 4.
//counter.getHits(300);
//
//// get hits at timestamp 301, should return 3.
//counter.getHits(301); 
//Follow up:
//What if the number of hits per second could be very large? Does your design scale?
//    


//思想还是前缀和，当前的前缀和 - 300之前的前缀和，问题是有可能 - 300没有正好hit过，所以用map, 可以配合使用upper_bound 函数。
    
    
class HitCounter {
    // int past300;
    int cur;
    map<int,int> mymap;
public:
    /** Initialize your data structure here. */
    HitCounter(): cur(0) {
        mymap[0] = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        ++cur;
        mymap[timestamp] = cur;

    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        
        if(timestamp-300 < 0) {
            return cur;
        }
        auto it = mymap.upper_bound(timestamp-300); 
        --it;

        return cur - it->second;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */