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


进一步优化： 记录每里面的number的最大值次大值，最小值和次小值，只要value大于两个最大值相加，或者两个value小于两个最小值相加都返回false。一开始最大值最小值要置为int_max和int_min所以得设置成long long
class TwoSum {
    unordered_map<int,int> mymap;
    long long max1;
    long long max2;
    long long min1;
    long long min2;
public:
    
    TwoSum(): max1(INT_MIN), max2(INT_MIN), min1(INT_MAX), min2(INT_MAX) {}

    // Add the number to an internal data structure.
	void add(int number) {
	    ++mymap[number];
        
        if(number > max1) {
            max2 = max1;
            max1 = number;
        }
        
        else if(number > max2) {
            max2 = number;
        }
        
        if(number < min1) {
            min2 = min1;
            min1 = number;
        }
        
        else if(number < min2) {
            min2 = number;
        }
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    
	    if(value > max1 + max2 || value < min1 + min2) return false;
	   
	    for(auto it = mymap.begin(); it!= mymap.end(); ++it) {
	        if(mymap.count(value - it->first)) {
	            if(value!=(it->first)>>1 || it->second > 1) return true;
	        }
	    }
	    
	    return false;
	}
};
    