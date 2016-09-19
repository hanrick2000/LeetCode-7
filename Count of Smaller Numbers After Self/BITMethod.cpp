//You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
//Example:
//
//Given nums = [5, 2, 6, 1]
//
//To the right of 5 there are 2 smaller elements (2 and 1).
//To the right of 2 there is only 1 smaller element (1).
//To the right of 6 there is 1 smaller element (1).
//To the right of 1 there is 0 smaller element.
//Return the array [2, 1, 1, 0].


这题用BIT的思想，思想很简单，在BIT中要想统计有多少数比x小，就求sum(x-1), 这题反向构造BIT即可。不过有一个问题，假设x很大怎么办？999999999，我们构建的数组要占用很大空间，1个典型的做法就是离散化+去重+排序。  比如把5,3,3, 1  离散化映射成 3 2 1. 然后将原始数组按照映射，放进数组，然后求sum即可。



class BIT{
    
    int len;
    vector<short> array;
    
    int lowBit(int index) {
        return index&(-index);
    }
    
public:
    BIT(int n): len(n), array(n+1,0) {}
    
    int sum(int index) {
        int res = 0;
        
        while(index > 0) {
            res+=array[index];
            index -= lowBit(index);
        }
        
        return res;
    }
    
    void add(int index, int delta = 1) {
        
        while(index <= len) {
            
            array[index] += delta;
            
            index += lowBit(index); 
            
        }
    }
};


struct Node {
    
    int val;
    int order;
    
    Node(): val(0), order(0) {}
    Node(int v, int o): val(v), order(o) {}
    
};

bool compare(const Node &a, const Node &b) {
    return a.val < b.val;
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        vector<Node> tmp;
        unordered_set<int> myset;
        vector<int> inums;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(myset.find(nums[i])!=myset.end()) {
                continue;
            }
            myset.insert(nums[i]);
            inums.push_back(nums[i]);
        }
        
        sort(inums.begin(), inums.end());
        
        unordered_map<int, int> mymap;
        
        for(int i = 0; i < inums.size(); ++i) {
            mymap[inums[i]] = i+1;
        }
        
        BIT tree(nums.size());
        
        vector<int> res(nums.size(), 0);
        
        for(int i = nums.size()-1; i >=0; --i) {
            res[i] = tree.sum(mymap[nums[i]]-1);
            tree.add(mymap[nums[i]]);
        }
        
        
        return res;
    }
};