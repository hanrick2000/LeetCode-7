A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.
    

//思路就是用II在这些范围里面生成反转数，然后把不符合要求的去掉。只要头尾两个位数的生成需要生成，其他返回数目就可以了。
    
class Solution {
public:

    int findStrobogrammaticNumber(int n) {
        int a0 = 1, a1 = 3;
        
        if(!(n&1)) {
            for(int i = 2; i< n; i+=2)  a0 *= 5;

            return 4*a0;
        }

        for(int i = 3; i< n; i+=2) a1 *= 5;
      
        return 4*a1;
    }


    int findStrobogrammaticLowerThanX(int n, long long y) {
        vector<string> p0 = {""}, p1 = {"0","1","8"};
        int res = 0;
        
        if(!(n&1)) {
            
            for(int i = 2; i <= n; i+=2) {
                
                vector<string> tmp;
                
                for(auto x: p0) {
                    if(i!=n) {
                        tmp.push_back("0" + x + "0");
                        tmp.push_back("1" + x + "1");
                        tmp.push_back("6" + x + "9");
                        tmp.push_back("8" + x + "8");
                        tmp.push_back("9" + x + "6");
                    }
                    
                    else {

                        if(stoll("1" + x + "1") <= y) {
                            ++res;
                        }
                        
                        if(stoll("6" + x + "6") <= y) { 
                            ++res;
                        }
                        
                        if(stoll("8" + x + "8") <= y) {
                            ++res;
                        }
                        if(stoll("9" + x + "9") <= y) {
                            ++res;
                        }
                    }
                }
                
                p0 = tmp;
            }
            
            return res;
        
        }
        
        for(int i = 3; i <= n; i+=2) {
                
            vector<string> tmp;
                
            for(auto x: p1) {
                if(i!=n) {
                    tmp.push_back("0" + x + "0");
                    tmp.push_back("1" + x + "1");
                    tmp.push_back("6" + x + "9");
                    tmp.push_back("8" + x + "8");
                    tmp.push_back("9" + x + "6");
                    
                }
                    
                else {

                        if(stoll("1" + x + "1") <= y) {
                            ++res;
                        }
                        
                        if(stoll("6" + x + "6") <= y) { 
                            ++res;
                        }
                        
                        if(stoll("8" + x + "8") <= y) {
                            ++res;
                        }
                        if(stoll("9" + x + "9") <= y) {
                            ++res;
                        }
                }
            }
                
            p1 = tmp;
        }

        return res;
  
    }


    vector<string> findStrobogrammatic(int n) {
        vector<string> p0 = {""}, p1 = {"0","1","8"};
        
        if(!(n&1)) {
            
            for(int i = 2; i <= n; i+=2) {
                
                vector<string> tmp;
                
                for(auto x: p0) {
                    if(i!=n) {
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
        
        for(int i = 3; i <= n; i+=2) {
                
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

    int strobogrammaticInRange(string low, string high) {
        
        if(stoll(low)>stoll(high)) return 0;

        int l = low.size(), r = high.size();
        int res = 0;
        
        for(int i = l+1; i < r; ++i) {
            res += findStrobogrammaticNumber(i);
        }
        
        vector<string> r1 = findStrobogrammatic(l);
        
        if(l == r) {
            
            for(auto x: r1) if(stoll(x)>=stoll(low)&&stoll(x)<=stoll(high)) ++res;
            
            return res;
            
        }

        for(auto x: r1) {
            if(stoll(x) >= stoll(low)) ++res;
        }
        
        
        res += findStrobogrammaticLowerThanX(r,stoll(high));
        
        
        return res;
        
    }
};