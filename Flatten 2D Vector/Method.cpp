//Implement an iterator to flatten a 2d vector.
//
//For example,
//Given 2d vector =
//
//[
//  [1,2],
//  [3],
//  [4,5,6]
//]
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].
//
//Hint:
//
//How many variables do you need to keep track?
//Two variables is all you need. Try with x and y.
//Beware of empty rows. It could be the first few rows.
//To write correct code, think about the invariant to maintain. What is it?
//The invariant is x and y must always point to a valid point in the 2d vector. Should you maintain your invariant ahead of time or right when you need it?
//Not sure? Think about how you would implement hasNext(). Which is more complex?
//Common logic in two different places should be refactored into a common method.

//没啥难度注意空行。x,y一定要保持在下一个元素上，这样hasnext就O(1)时间够了。

class Vector2D {
    int x;
    int y;
    vector<vector<int>> vec;

public:
    Vector2D(vector<vector<int>>& vec2d) {
        x = 0;
        y = 0;
        vec = vec2d;
        
        while(x<vec.size() &&vec[x].size()==0) {
            ++x;
        }
    }

    int next() {
        int a = vec[x][y++];
        if(y == vec[x].size()) {
            y = 0;
            ++x;
            while(vec[x].size()==0) {
                ++x;
            }
        }
        return a;
    }

    bool hasNext() {
        return x != vec.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */