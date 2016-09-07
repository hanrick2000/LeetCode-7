//A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
//Write a function to determine if a number is strobogrammatic. The number is represented as a string.
//
//For example, the numbers "69", "88", and "818" are all strobogrammatic.

傻逼题，和palindrom 很像

class Solution {
public:
    bool isStrobogrammatic(string num) {
        
        int mymap[10] = {0,1,-1,-1,-1,-1,9,-1,8,6};
        
        int p = 0, q = num.size()-1;
        
        while(p <= q) {
            
            if(mymap[num[p++]-'0'] != num[q--]-'0') {
                return false;
            }
        }
        return true;
    }
};



