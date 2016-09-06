//Implement the following operations of a stack using queues.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//empty() -- Return whether the stack is empty.
//Notes:
//You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
//Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
//You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
//Update (2015-06-11):
//The class name of the Java function had been updated to MyStack instead of Stack.

两个队列实现栈，每一次push,就往空的那个队列去push，每一次push,记录下新的top, getTop就返回top.问题是pop，pop在非空的那一个队列依次弹东西出去，弹到另一个空队列，最后一个直接弹出去，倒数第二个赋值给top.
    
所以综上所述，push耗时O(1).gettop O(1), pop,耗时   o(N). 

class Stack {
    
    queue<int> que1;
    queue<int> que2;
    int mytop;
public:
    // Push element x onto stack.
    void push(int x) {
        if(que2.size()) {
            que2.push(x);
        }
        else {
            que1.push(x);
        }
        mytop = x;
    }
    
    // Removes the element on top of the stack.
    void pop() {
        if(que1.size()) {
            while(que1.size()!=1) {
                if(que1.size()==2) mytop = que1.front();
                que2.push(que1.front());
                que1.pop();
                
            }
            
            que1.pop();
        }
        else {
            while(que2.size()!=1) {
                if(que2.size()==2) mytop = que2.front();
                que1.push(que2.front());
                que2.pop();
            }
            
            que2.pop();
        }
    }
    
    // Get the top element.
    int top() {
        return mytop;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return !(que1.size() + que2.size());
    }
};