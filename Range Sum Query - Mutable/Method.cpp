//Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
//The update(i, val) function modifies nums by updating the element at index i to val.
//Example:
//Given nums = [1, 3, 5]
//
//sumRange(0, 2) -> 9
//update(1, 2)
//sumRange(0, 2) -> 8
//Note:
//The array is only modifiable by the update function.
//You may assume the number of calls to update and sumRange function is distributed evenly.


那很明确了，就是用BIT。记住，BIT里的array表示那个前缀和。不是array的元素。而且BIT是从下标1开始的。
    
    

class BIT{
    
    int len;
    vector<int> array;
    vector<int> arr;
    
    inline int lowBit(int index) {
        return index&(-index);
    }
    
public:
    BIT(int n): len(n), array(n+1), arr(n) {}
    
    int sum(int index) {
        int res = 0;
        
        for(int i = index; i ; i-=lowBit(i)) res+=array[i];
        
        return res;
    }
    
    void add(int index, int delta = 1) {
        
        for(int i = index; i <= len; i+= lowBit(index)) array[i] += delta;
    }
    
    void set2(int index, int val) {
        arr[index] = val;
    }
    
    void set(int index, int val) {
        
        add(index, val - arr[index-1]);
        arr[index-1] = val;
    }
};


class NumArray {
    BIT tree;
public:
    NumArray(vector<int> &nums): tree(nums.size()) {
        
        for(int i = 0; i < nums.size(); ++i) {
            tree.add(i+1,nums[i]);
            tree.set2(i,nums[i]);
        }
        
    }
    
    void update(int i, int val) {
        
        tree.set(i+1, val);
    }
    
    int sumRange(int i, int j) {
        
        return  tree.sum(j+1) - tree.sum(i);
    }
};



// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);