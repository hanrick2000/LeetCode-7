//Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
//
//"abc" -> "bcd" -> ... -> "xyz"
//Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
//
//For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
//A solution is:
//
//[
//  ["abc","bcd","xyz"],
//  ["az","ba"],
//  ["acef"],
//  ["a","z"]
//]

//把所有string都shift以a开头就可以了。用hashmap记录在vector的下标


class Solution {
public:

    string normalize(string s) {
        if(s=="") return "";
        
        int len = s[0] - 'a';
        
        for(int i = 0; i < s.size(); ++i) {
            s[i] -= len;
            if(s[i] < 'a') s[i]+=26;
        }
        
        return s;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        vector<vector<string>> res;
        
        unordered_map<string,int> mymap; 
                
        for(int i = 0; i < strings.size(); ++i) {
            string tmp = normalize(strings[i]);
            if(mymap.find(tmp)!=mymap.end()) {
                res[mymap[tmp]].push_back(strings[i]);
            }
            
            else {
                mymap[tmp] = res.size();
                res.push_back({strings[i]});
            }
        }
        
        return res;
    }
};

