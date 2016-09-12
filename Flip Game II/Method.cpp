//You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
//
//Write a function to determine if the starting player can guarantee a win.
//
//For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".
//
//Follow up:
//Derive your algorithm's runtime complexity.


最基本的用回溯，canWinHelper表示至少有一种可能赢，那么即对方一种赢法都没有时，就可以返回true。T（n) = (n-2)O(n-2), O(n!!)

class Solution {
public:
    
    bool canWinHelper(string &s) {
        for(int i = 0; i < int(s.size())-1; ++i) {
            if(s[i]==s[i+1]&&s[i] == '+') {
                s[i] = s[i+1] = '-';
                if(!canWinHelper(s)) {
                    s[i] = s[i+1] = '+';
                    return true;
                }
                s[i] = s[i+1] = '+';
            }
        }
        
        return false;
    }


    bool canWin(string s) {
    
        return canWinHelper(s);
    }
};

然后用memo:时间复杂度化为多项式

bool canWinHelper(string &s,unordered_map<string,bool> &mp) {
        
        if(mp.find(s)!=mp.end()) return mp[s];
        
        
        for(int i = 0; i < int(s.size())-1; ++i) {
            if(s[i]==s[i+1]&&s[i] == '+') {
                s[i] = s[i+1] = '-';
                if(!canWinHelper(s,mp)) {
                    s[i] = s[i+1] = '+';
                    mp[s] = true;
                    return true;
                }
                s[i] = s[i+1] = '+';
            }
        }
        mp[s] = false;
        return false;
    }


    bool canWin(string s) {
        
        unordered_map<string,bool> mp;
        
        return canWinHelper(s,mp);
    }