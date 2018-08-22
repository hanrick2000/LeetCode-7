//Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
//Examples:
//
//s = "leetcode"
//return 0.
//
//s = "loveleetcode",
//return 2.
//Note: You may assume the string contain only lowercase letters.

//无语  直接hash 

class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> visited(26,false); 
    
        for(int i = 0; i < s.size(); ++i) {
            ++visited[s[i]-'a'];
        }
        
        for(int i = 0; i < s.size(); ++i) {
            if(visited[s[i]-'a'] == 1) return i;
        }

        return -1;
    }
    
    int firstUniqChar(string s) {
        
        vector<pair<int,int>> visited(26, make_pair(0,-1)); 
        
        for(int i = 0; i < s.size(); ++i) {
            if(visited[s[i]-'a'].second == -1) visited[s[i]-'a'].second = i;

            ++visited[s[i]-'a'].first;
        }
        
        int mini = s.size();
        
        for(int i = 0; i < visited.size(); ++i) {
            if(visited[i].first == 1) mini = min(mini, visited[i].second);
        }
        
        return mini == s.size()? -1:mini;
    }

    
    只扫描一遍string, 用hash记录每一个字符出现的index,初始化都为-1,  第一次出现设为index, 第二次出现设为-2.这样下一遍扫描一下hashmap找最小的index即可。
class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> mymap(26,-1);

        for(int i = 0; i < s.size(); ++i) {

            if(mymap[s[i] -'a'] == -1) mymap[s[i] - 'a'] = i;
            
            else mymap[s[i] - 'a'] = -2;
        }
        
        int res = s.size();
        
        for(int i = 0; i < mymap.size(); ++i) {
            if(mymap[i] >= 0) {
                res = min(res,mymap[i]);
            } 
        }
        return res == s.size()? -1:res;
    }
};
    
};