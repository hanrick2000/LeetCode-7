//There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
//
//For example,
//Given the following words in dictionary,
//
//[
//  "wrt",
//  "wrf",
//  "er",
//  "ett",
//  "rftt"
//]
//The correct order is: "wertf".
//
//Note:
//You may assume all letters are in lowercase.
//If the order is invalid, return an empty string.
//There may be multiple valid order of letters, return any one of them is fine.

//这题先用hashmap 记录下所有的先序关系，即出发的边，char- set<char>..这种类型，然后记录下入度。还要记录下所有的字符集。然后进行拓补排序。 这题不能光光用一个整数记录每一个字符多少入度，因为这里边是会重复的， a,b这样的对在里边出现后会使得b的入度大于1.course schedule 那道题就不同，它不会出现重复边。这道题还要输出这些字符，所以得用字符集判定一个字符到底是没有入度还是压根就不存在字典里。还有在que里面挑出没有入度的节点，然后去边时，可以不处理 邻接表，只需处理入度表就行。这题不会有自环。最后剩下的那些有入度的字符就是环。

class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        
        vector<unordered_set<int>> adjacencyList(26);
        vector<bool> charSet(26,false);
        vector<unordered_set<int>> indegree(26);

        for(auto x: words) {
            for(auto c: x) {
                charSet[c-'a'] = true;
            }
        }
        
        for(int i = 1; i < words.size(); ++i) {
            int j = 0;
            for(; j < words[i].size()&&j < words[i-1].size(); ++j) {
                if(words[i][j] != words[i-1][j]) {
                    adjacencyList[words[i-1][j]-'a'].insert(words[i][j]-'a');
                    indegree[words[i][j]-'a'].insert(words[i-1][j]-'a');
                    break;
                }
            }
            if(j == words[i].size()&&j < words[i-1].size()) return "";            
        }
 
        queue<int> myque;
        
        string res;
        
        for(int i = 0; i < 26; ++i) {
            if(charSet[i]&&indegree[i].empty()) myque.push(i);
        }
        
        while(myque.size()) {
            
            int tmp = myque.front();
            myque.pop();
            
            res += tmp + 'a';
            charSet[tmp] = false;
            
            for(auto x: adjacencyList[tmp]) {
                
                indegree[x].erase(tmp);
                
                if(indegree[x].empty()) myque.push(x);
                
                // adjacencyList[tmp].erase(x);
            }
        }
   
        for(int i = 0; i < 26; ++i) {
            if(charSet[i]&&indegree[i].size()) return "";
        }
        
        return res;

    }
};
