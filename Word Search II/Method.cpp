//Given a 2D board and a list of words from the dictionary, find all words in the board.
//
//Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
//For example,
//Given words = ["oath","pea","eat","rain"] and board =
//
//[
//  ['o','a','a','n'],
//  ['e','t','a','e'],
//  ['i','h','k','r'],
//  ['i','f','l','v']
//]
//Return ["eat","oath"].
//Note:
//You may assume that all inputs are consist of lowercase letters a-z.
//
//click to show hint.
//
//You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
//
//If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.


//这题迷迷糊糊，暴力搜索会超时我们发现一个规律，如果在方格里搜索到的一个状态（字符串不属于字典树里面的前缀，那么可以直接回溯，）如果这个单词出现在字典树中，就可以放入结果，但此时还没完，还要继续dfs搜索其他的方格。最后的结果可能要去重。

class TrieNode {
    
    
public:
    // Initialize your data structure here.
    TrieNode(){memset(characters,NULL,sizeof(characters));};
    TrieNode* characters[27];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        nullString = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {

        TrieNode* p = root;
        
        for(int i = 0; i < word.size(); ++i) {
            if(!p->characters[word[i] - 'a']) {
                p->characters[word[i] - 'a']= new TrieNode();
            }
            p = p->characters[word[i] - 'a'];
        }
        
        p->characters[26] = nullString;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        
        for(int i = 0; i < word.size(); ++i) {
            TrieNode* tmp = p->characters[word[i] - 'a'];
            if(!tmp) return false;
            p = tmp;
        }
      
        return p->characters[26];
        
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        
        for(int i = 0; i < prefix.size(); ++i) {
            TrieNode* tmp = p->characters[prefix[i] - 'a'];
            if(!tmp) return false;
            p = tmp;
        }
        
        return true;
    }

    
private:
    TrieNode* root;
    TrieNode* nullString;

};

class Solution {
    
    Trie t;
public:

    void dfs(vector<vector<char>> &board, int i, int j, string &cur, vector<string> &res) {
        
        if(i<0||i>board.size()-1||j<0||j>board[0].size()-1||board[i][j] == '\0') {
            return;
        }
        char c = board[i][j];
        cur += c;
        
        board[i][j] = '\0';

        if (!t.startsWith(cur))  {   //可以回溯。
            board[i][j] = c;
            cur.pop_back();
            return;
        }
        
        if (t.search(cur)) {   //找到一个结果
            res.push_back(cur);
        }
        
        dfs(board, i-1,j,cur,res);  //继续找包含这个前缀的其他词
        dfs(board, i+1,j,cur,res);
        dfs(board, i,j-1,cur,res);
        dfs(board, i,j+1,cur,res);
     
        board[i][j] = c;
        cur.pop_back();
        return ;
        
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vector<string> res; 

        for(auto x: words) t.insert(x);

        string cur;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                dfs(board, i,j,cur, res);
            }
        }

        unordered_set<string> myres(res.begin(),res.end());
        
        res = vector<string>(myres.begin(),myres.end());
        
        return res;
    }
};