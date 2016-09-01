//Design and implement a TwoSum class. It should support the following operations: add and find.
//
//add - Add the number to an internal data structure.
//find - Find if there exists any pair of numbers which sum is equal to the value.
//
//For example,
//add(1); add(3); add(5);
//find(4) -> true
//find(7) -> false


用一个hash表存数和出现的次数，find时看看value-x是不是也在hash表中，如果value-x == x，看看x出现的次数。


class TwoSum {
public:
    
    unordered_map<int,int> mymap; //(key,number) pair
    
    // Add the number to an internal data structure.
	void add(int number) {
	    ++mymap[number];
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {

	    for(auto x: mymap) {
	        int t = value-x.first;
	        if ((x.first!=t && mymap.find(t)!=mymap.end())||(x.first==t&&x.second>1)) return true;
	    }
	    
	    
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);