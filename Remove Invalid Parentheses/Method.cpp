//Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
//
//Note: The input string may contain letters other than the parentheses ( and ).
//
//Examples:
//"()())()" -> ["()()()", "(())()"]
//"(a)())()" -> ["(a)()()", "(a())()"]
//")(" -> [""]

BFS, 对于s，先判断它是不是合法的括号匹配，合法的话，直接放结果，就不用对它进行BFS搜索了。BFS搜索，删除每一个左右括号，放入队列中继续进行，如果在找到任何答案之前的放入队列的字符串，只需要判断他们是不是符合，不用继续搜索了。为了防止重复用map记录是字符串否出现在队列里过，

有个问题，会不会出现某一层找到了valid的解，之后队列里下一层的字符串也valid，从而造成不同长度的字符串都存在结果中？
答案是否定的，因为如果当前层valid，那么下层移除括号必然不会valid，因为括号两两匹配，i层valid，i+1层移除一个括号必然会使他对应的括号单着，所有invalid

class Solution {
public:

    bool isvalid(string &s) {
        
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i]=='(') ++count;
            if(s[i]==')') {
                --count;
                if(count < 0) return false;
            }
        }
        
        return count == 0;
        
    }

    vector<string> removeInvalidParentheses(string s) {
        
        unordered_set<string> mymap;
        
        queue<string> myque;
        
        myque.push(s);
        
        mymap.insert(s);
        
        vector<string> res;
        
        bool found = false;
        
        while(myque.size()) {
            
            string tmp = myque.front();
            myque.pop();
            
            if(isvalid(tmp)) {
 
                res.push_back(tmp);
                found = true;
            }
            
            if(found) continue;
            
            for(int i = 0; i < tmp.size(); ++i) {
                
                if(tmp[i] != '(' && tmp[i]!=')') continue;
                
                string t = tmp.substr(0,i) + tmp.substr(i+1);

                if(mymap.find(t)==mymap.end())  {
                    myque.push(t);
                    mymap.insert(t);
                }
            }
        }
        
        return res;
        
    }
};