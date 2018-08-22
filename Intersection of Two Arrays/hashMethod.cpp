//Given two arrays, write a function to compute their intersection.
//
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
//
//Note:
//Each element in the result must be unique.
//The result can be in any order.

为了防止一个重复的数被 加到res里去，还得再加一个set。

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> map1,map2;
        vector<int> res;
        
        for(int i = 0; i < nums1.size(); ++i) {
            map1.insert(nums1[i]);
        }
        
        for(int i = 0; i < nums2.size(); ++i) {
            if(map1.find(nums2[i])!=map1.end()&&map2.find(nums2[i])==map2.end()) {
                res.push_back(nums2[i]);
                map2.insert(nums2[i]);
            }
        }
        
        return res;
        
    }
};

    不如这么做：先把nums1所有数用无序表记录下来， 然后遍历nums2, 如果存在在无序表中，加到res中，无序表中删除这个元素。
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> mymap;
        
        vector<int> res;
        for(auto x: nums1)  mymap.insert(x);
        
        for(auto x: nums2) {
            if(mymap.count(x)) {
                res.push_back(x);
                mymap.erase(x);
            }
        }
        
        return res;
    }