//这个方法运用自定义class 实现了循环队列。   比queue 更加省空间， 
//空间O(n) 时间O(1)

class myqueue {
    int* base;
    int size;
    int front;
    int rear;
public:
    myqueue(int size=1): size(size+1),front(0),rear(0) {
        base = new int[size+1];
    }
    
    ~myqueue() {
        delete [] base;
    }
    
    bool isEmpty() {
        return front==rear;
    }
    
    void enQueue(int val) {
        
        if((rear+1)%size == front) return;
        
        base[rear] = val;
        rear = (++rear)%size;
    }

    int deQueue() {
        if(isEmpty()) return -1;
        
        int e = base[front];
        front = (++front)%size;
        
        return e;
    }
    
    int getSize() {
        return (rear-front+size)%size;
    }
    
    bool filled() {
        return getSize()==size-1;
    }
};



class MovingAverage {
    myqueue que;
    long long sum;
public:
    /** Initialize your data structure here. */
    
    MovingAverage(int size): sum(0),que(size){}
    
    double next(int val) {
    
        if(que.filled()) {
            sum -= que.deQueue();
        }
        
        que.enQueue(val);
        sum+=val;
        
        return sum*1.0/que.getSize();
        
    }
};
