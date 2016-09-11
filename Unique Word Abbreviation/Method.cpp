//An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:
//
//a) it                      --> it    (no abbreviation)
//
//     1
//b) d|o|g                   --> d1g
//
//              1    1  1
//     1---5----0----5--8
//c) i|nternationalizatio|n  --> i18n
//
//              1
//     1---5----0
//d) l|ocalizatio|n          --> l10n
//Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
//
//Example: 
//Given dictionary = [ "deer", "door", "cake", "card" ]
//
//isUnique("dear") -> false
//isUnique("cart") -> true
//isUnique("cane") -> false
//isUnique("make") -> true


//这题最讨厌的例子就是
//["hello"],isUnique("hello")
//["a","a"],isUnique("a")
//["dog"],isUnique("dig"),isUnique("dug"),isUnique("dag"),isUnique("dog"),isUnique("doge")
//所以还得拷贝一份dictionary作为set.判断是否unique时如果压缩码不存在，肯定unique，如果压缩码次数大于1，肯定不unique（记得构造函数里，发现重复词要忽略）如果等于1得看，这个word本身是不是出现在dict中，是的话返回true，否则false。

class ValidWordAbbr {
    
    unordered_set<string> dict;
    unordered_map<string,int> abbr;
    
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(auto x: dictionary) {
            if(dict.find(x)!=dict.end()) continue;
            dict.insert(x);
            string tmp;
            
            if(x!="") {
                if(x.size()>2) {
                    tmp = x.substr(0,1) + to_string(x.size()-2) + x.back();
                }
                else {
                    tmp = x.substr(0,1) + x.back();
                }
            }
            
            abbr[tmp]++;
        }
        
    }
    
    bool isUnique(string word) {
        string tmp;
        
        if(word!="") {
            if(word.size()>2) {
                tmp = word.substr(0,1) + to_string(word.size()-2) + word.back();
            }
            else {
                tmp = word.substr(0,1) + word.back();
            }
        }
        
        if(abbr.find(tmp)==abbr.end()) {
            return true;
        }
        
        if(abbr[tmp]>1) return false;
        
        return dict.find(word) !=dict.end();
        
        // ["hello"],isUnique("hello")
        // ["a","a"],isUnique("a")
        // ["dog"],isUnique("dig"),isUnique("dug"),isUnique("dag"),isUnique("dog"),isUnique("doge")
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");