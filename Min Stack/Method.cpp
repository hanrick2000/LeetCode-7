//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.
//Example:
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns -3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns -2.


//重点在于如何在O(1)时间返回最小值，我们可以始终维护一个变量纪录最小值，在push的时候可以o（1）时间更新，在pop时用O(n)时间更新一下。  因为没进行n次o(1)的push操作才会有一次pop出最小值的情况，所以均摊下来是O(1).

class MinStack {
    vector<int> mystack;
    int min_element ;
public:
    /** initialize your data structure here. */
    
    MinStack() {
        min_element = INT_MAX;
    }
    
    void push(int x) {
        
        mystack.push_back(x);
        min_element = min(min_element, x);
    }
    
    void pop() {
        if(mystack.back()==min_element) {
            mystack.pop_back();
            min_element = INT_MAX;
            for(auto &x: mystack) {
                min_element = min(min_element,x);
            }
        }
        else {
            mystack.pop_back();
        }
    }
    
    int top() {
        return mystack.back();
    }
    
    int getMin() {
        return min_element;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
