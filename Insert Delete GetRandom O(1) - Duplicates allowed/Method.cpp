//Design a data structure that supports all following operations in average O(1) time.
//
//Note: Duplicate elements are allowed.
//insert(val): Inserts an item val to the collection.
//remove(val): Removes an item val from the collection if present.
//getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
//Example:
//
//// Init an empty collection.
//RandomizedCollection collection = new RandomizedCollection();
//
//// Inserts 1 to the collection. Returns true as the collection did not contain 1.
//collection.insert(1);
//
//// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
//collection.insert(1);
//
//// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
//collection.insert(2);
//
//// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
//collection.getRandom();
//
//// Removes 1 from the collection, returns true. Collection now contains [1,2].
//collection.remove(1);
//
//// getRandom should return 1 and 2 both equally likely.
//collection.getRandom();

这题在I的基础上只要用map记录每一个数的index的集合就可以了，不过记得判断集合里面有没有这个index还有可能是有[index]key 只不过这个set是空的。 remove的时候思想和I类似，也是用最后的去覆盖当前位置，然后改相应的map和vector，要专门处理，如果删除的是最后的位置，hashmap的处理是不同的。

class RandomizedCollection {
    unordered_map<int,set<int>> mymap;
    vector<int> myarr;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
        srand(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        
        if(mymap.find(val) == mymap.end() || mymap[val].size() == 0) {
            
            mymap[val].insert(myarr.size());
            
            myarr.push_back(val);
            
            return true;
        }
        
        mymap[val].insert(myarr.size());
        
        myarr.push_back(val);
        
        return false;
        
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        
        if(mymap.find(val) == mymap.end() || mymap[val].size() == 0) return false;
        
        auto it = mymap[val].begin();
        
        int index = *it;
        
        if(index!=myarr.size()-1) {
            
            myarr[index] = myarr.back();
        
            mymap[val].erase(it);
            
            mymap[myarr.back()].erase(myarr.size()-1);
            
            mymap[myarr.back()].insert(index);
            
            myarr.pop_back();
        }
        
        
        else {
            
            mymap[val].erase(it);
            
            myarr.pop_back();
        }

        return true;
        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        
        return myarr[rand()%myarr.size()];
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */