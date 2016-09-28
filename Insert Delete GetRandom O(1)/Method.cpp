//Design a data structure that supports all following operations in average O(1) time.
//
//insert(val): Inserts an item val to the set if not already present.
//remove(val): Removes an item val from the set if present.
//getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
//Example:
//
//// Init an empty set.
//RandomizedSet randomSet = new RandomizedSet();
//
//// Inserts 1 to the set. Returns true as 1 was inserted successfully.
//randomSet.insert(1);
//
//// Returns false as 2 does not exist in the set.
//randomSet.remove(2);
//
//// Inserts 2 to the set, returns true. Set now contains [1,2].
//randomSet.insert(2);
//
//// getRandom should return either 1 or 2 randomly.
//randomSet.getRandom();
//
//// Removes 1 from the set, returns true. Set now contains [2].
//randomSet.remove(1);
//
//// 2 was already in the set, so return false.
//randomSet.insert(2);
//
//// Since 1 is the only number in the set, getRandom always return 1.
//randomSet.getRandom();

//insert 和 remove  用O(1)完成显然要用hashtable. 用O（1） 完成随机返回元素，就得用vector，关键怎么是删除？可以hashtable记录元素在vector的下标，  删除时可以把vector的最后一个元素覆盖到该元素上，然后更新hashmap.vector再pop.

class RandomizedSet {
    unordered_map<int,int> mymap;
    vector<int> myarr;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mymap.find(val)!=mymap.end())  return false;
        
        mymap[val] = myarr.size();
        myarr.push_back(val);
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mymap.find(val)==mymap.end())  return false;
      
        mymap[myarr.back()] = mymap[val];

        swap(myarr.back(), myarr[mymap[val]]);
        
        mymap.erase(val);
        
        myarr.pop_back();
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return myarr[rand()%myarr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */