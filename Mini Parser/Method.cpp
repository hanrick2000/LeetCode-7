//Given a nested list of integers represented as a string, implement a parser to deserialize it.
//
//Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//
//Note: You may assume that the string is well-formed:
//
//String is non-empty.
//String does not contain white spaces.
//String contains only digits 0-9, [, - ,, ].
//Example 1:
//
//Given s = "324",
//
//You should return a NestedInteger object which contains a single integer 324.
//Example 2:
//
//Given s = "[123,[456,[789]]]",
//
//Return a NestedInteger object containing a nested list with 2 elements:
//
//1. An integer containing value 123.
//2. A nested list containing two elements:
//    i.  An integer containing value 456.
//    ii. A nested list with one element:
//         a. An integer containing value 789.


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

//这题用栈，一看到'['说明是一个新的nestedinteger 开始，新建一个实例，压栈。如果看到是数字，循环到数字的末尾，然后新建一个数字的NI，压栈，如果看到,或者']'，那么表明栈顶上的那个NI结束了，该把它压进栈顶下的NI了，但这里有一个例外，就是空NI，就是'[]'这种情形。这种情况我们应该什么都不做，所以我们只能再安排一个变量isEmptyNi来确定当前栈顶的Ni到底是不是空，每一次遇到'['，置变量为false.遇到数字，置true，在遇到']'时如果变量为false 就不动，然后把变量置true。

class Solution {
public:
    NestedInteger deserialize(string s) {
        // s.insert(s.begin(), '[');
        // s+=']';
        if(s == "") return NestedInteger();
        if(s[0] != '[') return NestedInteger(stoi(s));
        
        stack<NestedInteger> mystack;
        bool emptyNi = false;;
        for(int i = 0; i < s.size(); ++i) {
            
            if(s[i] == '[') {
                NestedInteger a;
                emptyNi = false;
                mystack.push(a);
            }
        
            else if(s[i] == '-' || s[i]>='0'&&s[i]<='9' ) {
                int k = i+1;
                
                while(s[k]>='0' && s[k]<='9') {
                    ++k;
                }
                
                mystack.push(NestedInteger(stoi(s.substr(i, k-i))));
                i = k-1;
                emptyNi = true;
            }
            
            else  {
                if(emptyNi) {
                    NestedInteger a = mystack.top();
                    mystack.pop();
                    mystack.top().add(a);
                }
                
                emptyNi = true;
            }
        }
        

        return mystack.top();
        
    }
};