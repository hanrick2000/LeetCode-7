//Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
//
//Examples: 
//[2,3,4] , the median is 3
//
//[2,3], the median is (2 + 3) / 2 = 2.5
//
//Design a data structure that supports the following two operations:
//
//void addNum(int num) - Add a integer number from the data stream to the data structure.
//double findMedian() - Return the median of all elements so far.
//For example:
//
//add(1)
//add(2)
//findMedian() -> 1.5
//add(3) 
//findMedian() -> 2

//用两个堆做，一个大顶堆  一个小顶堆，两者数量相同，大顶堆的最大值比小顶堆小。

class MedianFinder {
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        
        if(maxHeap.size() == minHeap.size()) {
            
            if((minHeap.size()&&minHeap.top() >= num)||minHeap.empty()) {
                maxHeap.push(num);
            }
            
            else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            
        }
        
        else {
            
            if(maxHeap.top() >= num) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
            
            else {
                minHeap.push(num);
            }
        }
        
    }

    // Returns the median of current data stream
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) return 1.0*(maxHeap.top() + minHeap.top())/2; 
        
        return maxHeap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();