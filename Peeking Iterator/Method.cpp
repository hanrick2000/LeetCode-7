//Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().
//
//Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].
//
//Call next() gets you 1, the first element in the list.
//
//Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
//
//You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.
//
//Hint:
//
//Think of "looking ahead". You want to cache the next element.
//Is one variable sufficient? Why or why not?
//Test your design with call order of peek() before next() vs next() before peek().
//For a clean implementation, check out Google's guava library source code.
//Follow up: How would you extend your design to be generic and work with all types, not just integer?


需要一个提前的iterator peeker, 总是指向next（）的下一个要被访问的节点。所以每一次调用next时要把peeker也向后移，当然得在.Hasnext判断下移动，用一个整数p记录下peek->val,这样每一次peek时可以返回，不然指针要移动了。
在子类中如果想要重写父类的函数，可以用父类::方法名（）调用。


class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
    Iterator peekIter;
    int p;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums), peekIter(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        if(peekIter.hasNext()) {
            p = peekIter.next();
        }
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return p;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        
        if(peekIter.hasNext()) {
            p = peekIter.next();
        }
        
        return Iterator::next();
    }
    
    bool hasNext() const {
        return Iterator::hasNext();
    }
};