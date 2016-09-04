//Design a data structure that supports the following two operations:
//
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
//For example:
//
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true
//Note:
//You may assume that all words are consist of lowercase letters a-z.
//
//click to show hint.
//
//You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.

//就在实现trie上面多套用了一下dfs.


class TrieNode {
    
public:
    // Initialize your data structure here.
    TrieNode(){memset(characters,NULL,sizeof(characters));};
    TrieNode* characters[27];
};

class WordDictionary {
public:
    
    WordDictionary() {
        root = new TrieNode();
        nullString = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = root;
        
        for(int i = 0; i < word.size(); ++i) {
            if(!p->characters[word[i] - 'a']) {
                p->characters[word[i] - 'a']= new TrieNode();
            }
            p = p->characters[word[i] - 'a'];
        }
        
        p->characters[26] = nullString;
    }
    
    
    bool searchHelper(string &word, int depth, TrieNode* root) {
        if(depth == word.size()) return root->characters[26];
        
        if(word[depth] == '.') {
            for(int i = 0; i < 26; i++) {
                if(root->characters[i]) {
                    if(searchHelper(word, depth+1, root->characters[i])) return true;
                }
            }
            
            return false;
        }
        
        else {
            if(root->characters[word[depth]-'a']) {

                return searchHelper(word,depth+1,root->characters[word[depth]-'a']);
            }
            return false;
            
        }
        
    }
    
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode* p = root;
        
        return searchHelper(word,0,p);
        
    }
private:
    TrieNode* root;
    TrieNode* nullString;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");