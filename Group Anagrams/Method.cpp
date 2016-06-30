//Given an array of strings, group anagrams together.
//
//For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
//Return:
//
//[
//  ["ate", "eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]
//Note: All inputs will be in lower-case.

//这题很显然用hash表。hash表的key存的是目前为止 让每一个字符串以字典顺序排序后的集合，key值是该集合在vector中的下标。然后一边扫描就可以全部做完。时间空间O(n).

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> mymap;
        
        vector<vector<string>> res;
        string temp;
        for(auto &x: strs) {
            temp = x;
            sort(temp.begin(),temp.end());
            if(mymap.find(temp)==mymap.end()) {
                mymap[temp] = res.size();
                res.push_back({x});
            }
            else {
                res[mymap[temp]].push_back(x);
            }
        }
        
        return res;
    }
};