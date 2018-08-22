//Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//Only one letter can be changed at a time
//Each intermediate word must exist in the word list
//For example,
//
//Given:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//Return
//  [
//    ["hit","hot","dot","dog","cog"],
//    ["hit","hot","lot","log","cog"]
//  ]
//Note:
//All words have the same length.
//All words contain only lowercase alphabetic characters.
    
这道题很难的。大体框架是要BFS，每一个进入队列的单词都是wordlist里面的。然后记住，每一次wordi 转换成 其他word2时，要让word2的list保存前驱。这里的去重有点不太一样。每一次照理来说直接在wordlist里面删掉就表明访问过了，但是这里必须得同一层全部访问结束后再统一删除，原因是可能同一层多个词会同时连到下一个词i,如果当第一个词访问到i时，记录前驱后，i就进入队列了，同一层下一个词就会连接不到i。所以得同一层全部访问记录前驱后。在最后全部删除。同时，虽然我们在最后删除，但我们还是只能保证i只进入到队列里一次，否则显然路径结果会重复（试想一下i重复，那么之后i的子孙记录前驱是势必会记录多个i，那么最终生成的路径就会重复），所以我们用一个set来记录要被删掉的节点，如果已经在set中那么只是记录它的前驱节点，而不把它push到队列里去。  最后用一个dfs把全部路径恢复出来。

    void dfs(vector<vector<string>>& res, string cur, unordered_map<string, vector<string>> &path, string &beginWord, vector<string>& r, int j) {
        if(cur == beginWord) {
            res.push_back(r);
            return;
        }
        
        for(auto i = path[cur].begin(); i != path[cur].end(); ++i) {
            r[j-1] = *i;
            dfs(res, *i, path, beginWord, r, j-1);
        }
    }
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        
        int res = 1, len = beginWord.size(), shortLevel = INT_MAX;
        wordList.insert(endWord);
        queue<string> myque;
        unordered_map<string, vector<string>> path;
        myque.push(beginWord);
        bool can = false;
        
        while(myque.size())  {
            
            if(res > shortLevel) break;
            int l = myque.size();
            unordered_set<string> todelet;
            for(int k = 0; k < l; ++k) {
                
                string tmp = myque.front();
                myque.pop();
                if(tmp == endWord) {
                    shortLevel = res;
                    can = true;
                    break;
                }
                for(int i = 0; i < len; ++i) {
                    string t = tmp;
                    for(char c = 'a'; c <= 'z'; ++c) {
                        if(c == t[i]) continue;
                        tmp[i] = c;
                        if(wordList.count(tmp)) {
                            path[tmp].push_back(t);
                            if (!todelet.count(tmp)) {
                                myque.push(tmp);
                                //wordList.erase(tmp);
                                todelet.insert(tmp);
                            }
                         }
                        tmp = t;
                    }
                }
            }
            for(auto s: todelet) {
                wordList.erase(s);
            }
            ++res;
        }
        
        if (!can) {
            return {};
        }
        vector<vector<string>> res2;
        vector<string> r(shortLevel);
        r.back() = endWord;
    
        dfs(res2, endWord, path, beginWord, r, r.size()-1);
        
        return res2;
    }