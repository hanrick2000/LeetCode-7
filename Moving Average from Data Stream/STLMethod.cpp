//该方法用STL的queue，数据保存在队列里，然后每一次记录上次的sum,就可以通过出队入队迅速得到现在的值，
//空间O(n), 时间O(1);
class MovingAverage {
    queue<int> que;
    long long sum;
    int size;
public:
    /** Initialize your data structure here. */
    
    MovingAverage(int size): sum(0),size(size){}
    
    double next(int val) {
        que.push(val);
        sum+=val;
        
        if(que.size()>size) {
            sum -= que.front();
            que.pop();
        }
                
        return sum*1.0/que.size();
        
    }
};
