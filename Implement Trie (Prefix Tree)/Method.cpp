//Implement a trie with insert, search, and startsWith methods.
//
//Note:
//You may assume that all inputs are consist of lowercase letters a-z.

每一个节点包含一个hashset,对a-z的，注意还得有一位表示null, 及你得区分ab 和 abc在字典树中的区别。假设你树里有abc, 那么搜索ab是没有的，这时，我们就得看这一位了。注意，插入时，要判断当前字符在字典树中是否存在，不能重复创建。

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