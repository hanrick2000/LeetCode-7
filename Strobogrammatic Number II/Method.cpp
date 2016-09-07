//A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
//Find all strobogrammatic numbers that are of length = n.
//
//For example,
//Given n = 2, return ["11","69","88","96"].
//
//Hint:
//
//Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.


这题有些细节不容易想周全。大体上我们知道n的情况就是在n-2的所有情况里面在两边加上11,88,69,96.但是1001这种特例表明了 “00” 虽然作为n=2时时应当舍弃的，但作为n=4时用来递归的垫脚石，是得保留的。所以00只有当n时是不加在两边的，其他情况要加。
注意既然我们完全按照-2规则递归，那么一开始就可以确定从n=0时往上还是n=1时往上


class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> p0 = {""}, p1 = {"0","1","8"};
        
        if(!(n&1)) {   //n 偶数
              
            for(int i = 2; i <= n; i+=2) {
                
                vector<string> tmp;
                
                for(auto x: p0) {
                    if(i!=n) { //非常容易漏
                        tmp.push_back("0" + x + "0");
                    }
    
                    tmp.push_back("1" + x + "1");
                    tmp.push_back("6" + x + "9");
                    tmp.push_back("8" + x + "8");
                    tmp.push_back("9" + x + "6");
                }
                
                p0 = tmp;
            }
            
            return p0;
        
        }
        
        for(int i = 3; i <= n; i+=2) { //n 奇数
                
            vector<string> tmp;
                
            for(auto x: p1) {
                if(i!=n) {
                    tmp.push_back("0" + x + "0");
                }
    
                tmp.push_back("1" + x + "1");
                tmp.push_back("6" + x + "9");
                tmp.push_back("8" + x + "8");
                tmp.push_back("9" + x + "6");
            }
                
            p1 = tmp;
        }
        
        return p1;
    
    }
};