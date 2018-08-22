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
    
还有另外一个解法。每一次push,先把有元素的那一个栈里的元素全部按顺序移到另一个空队列，然后把新元素放到该队列，然后再把另外队列那些元素倒回来到该队列。O(n)
这样pop就是出有元素队列的队首O（1）。top也是返回队首， O(1)

    
用这个方法，  一个masterQue 主队列和 用一个tmp辅助队列。    每一次push时，先把所有的master里的内容依次push的tmp里，在把xpush到master里来，然后再把tmp的内容全部push还给master。每一次push前和push完后， tmp都是空的。
    
class Stack {
    queue<int> masterQue;
    queue<int> tmp;
public:
    // Push element x onto stack.
    void push(int x) {
        while(masterQue.size()) {
            tmp.push(masterQue.front());
            masterQue.pop();
        }
        masterQue.push(x);
        while(tmp.size()) {
            masterQue.push(tmp.front());
            tmp.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        masterQue.pop();
    }

    // Get the top element.
    int top() {
        return masterQue.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return masterQue.empty();
    }
};