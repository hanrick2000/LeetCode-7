//Given a non-empty array of integers, return the k most frequent elements.
//
//For example,
//Given [1,1,1,2,2,3] and k = 2, return [1,2].
//
//Note: 
//You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

//用堆做，不说了

struct comparator {
    
    bool operator () (const pair<int,int> &a, const pair<int,int> &b) {
        
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator> myheap; 
        unordered_map<int,int> hash;
        
        for(int i = 0; i < nums.size(); ++i) {
            ++hash[nums[i]];
        }
        for(auto it = hash.begin(); it!=hash.end(); ++it) {
            myheap.push(make_pair(it->first, it->second));
        }
        
        vector<int> res;
        
        while(k--&&myheap.size()) {
            res.push_back(myheap.top().first);
            myheap.pop();
        }
        return res;
        
    }
};