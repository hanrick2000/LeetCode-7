//Given a nested list of integers, implement an iterator to flatten it.
//
//Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//
//Example 1:
//Given the list [[1,1],2,[1,1]],
//
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
//
//Example 2:
//Given the list [1,[4,[6]]],
//
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

//用栈类似dfs, 每一次在调用next之前确保栈顶是interger, 返回时把栈顶如果不是integer的Ni展开来，放到栈里面，循环，直到栈顶是数字。只要栈非空就hasnext.

class NestedIterator {
    
    stack<NestedInteger> mystack;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {

        for(int i = nestedList.size()-1; i>=0; --i) {
            mystack.push(nestedList[i]);
        }
        
        while(mystack.size()&&!mystack.top().isInteger()) {
            vector<NestedInteger> level = mystack.top().getList();
            mystack.pop();
            for(int i = level.size()-1; i>=0; --i) {
                mystack.push(level[i]);
            }
        }
        return;
    }

    int next() {
        int res = mystack.top().getInteger();
        mystack.pop();
        
        while(mystack.size()&&!mystack.top().isInteger()) {
            vector<NestedInteger> level = mystack.top().getList();
            mystack.pop();
            for(int i = level.size()-1; i>=0; --i) {
                mystack.push(level[i]);
            }
        }
        
        return res;
    }

    bool hasNext() {
        return mystack.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */