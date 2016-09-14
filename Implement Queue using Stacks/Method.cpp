//Implement the following operations of a queue using stacks.
//
//push(x) -- Push element x to the back of queue.
//pop() -- Removes the element from in front of queue.
//peek() -- Get the front element.
//empty() -- Return whether the queue is empty.
//Notes:
//You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
//Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
//You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

用两个栈
一种：push时往A push. pop时如果B有元素就pop B的，没有的话  就把A全部push到b,再pop. top也是一样
push(o(1)) pop()平均O(1),top() 也是

第二种。push往a push 再弹出到B上。pop从b pop,和一本质上一样 只不过没有armotized .



class Queue {
    stack<int> stack1;
    stack<int> stack2;
    
public:

    // Push element x to the back of queue.
    void push(int x) {
        stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(stack2.size()) stack2.pop();
        else {
            
            while(stack1.size()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            stack2.pop();
            
        }
    }

    // Get the front element.
    int peek(void) {
        if(stack2.size()) return stack2.top();
        while(stack1.size()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        return stack2.top();
        
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return !(stack1.size()+stack2.size());
    }
};