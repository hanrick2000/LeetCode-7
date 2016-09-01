//Compare two version numbers version1 and version2.
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//You may assume that the version strings are non-empty and contain only digits and the . character.
//The . character does not represent a decimal point and is used to separate number sequences.
//For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
//Here is an example of version numbers ordering:
//
//0.1 < 1.1 < 1.2 < 13.37

//很麻烦的一道题，基本思路是对两个进行split('.')后，从头开始比较字符串所代表的数字。

class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int p = 0, q = 0;
        
        int v1 = 0, v2 = 0;
        version1 += ".0";   //防止出现不进入循环中'.'的判断
        version2 += ".0";
        
        while(p<version1.size()&&q<version2.size()) {
            if(version1[p]=='.'&&version2[q]=='.') {  //进入判断时中间形如01和0也能判断相等。
                if(v1 > v2) return 1;
                if(v1 < v2) return -1;
                v1 = 0;
                v2 = 0;
                
                ++p;
                ++q;
                continue;
            }
            
            if(version1[p]!='.') {
                v1 = 10*v1 + version1[p]-'0';
                ++p;
                
            }
            
            if(version2[q]!='.') {
                v2 = 10*v2 + version2[q] - '0';
                ++q;
                
            }
            
        }
        
        if(v1 > v2) return 1;
        if(v1 < v2) return -1;
        //其中一个已经结束，剩下一个还有一串.xxx在后头，只要出现非零，就可以证明大小
        if(p == version1.size()) {     
            while(q<version2.size()) {
                if(version2[q]!='.'&&version2[q]!='0') return -1;
                ++q;
            }
        }
        else {
            while(p<version1.size()) {
                if(version1[p]!='.'&&version1[p]!='0') return 1;
                ++p;
            }
        }
        
        return 0;
        
    }
};
//该解法是应用了c++里面的split函数。简单很多。

class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        std::string input = version1;
        std::istringstream ss(input);
        std::string token;
        vector<string> v1,v2;
        
        while(std::getline(ss, token, '.')) {
            // std::cout << token << '\n';
            v1.push_back(token);
            
        }
        
        input = version2;
        std::istringstream ss2(input);
        
        while(std::getline(ss2, token, '.')) {
            // std::cout << token << '\n';
            v2.push_back(token);
            
        }
        int i;
        for(i = 0; i < min(v1.size(),v2.size()); ++i) {
            if(stoi(v1[i]) < stoi(v2[i])) return -1;
            if(stoi(v1[i]) > stoi(v2[i])) return 1;
            
        }
        if(i == v1.size()) {
            while(i < v2.size()) {
                if(stoi(v2[i])>0) return -1;
                ++i;
            }
        }
        
        else {
            while(i < v1.size()) {
                if(stoi(v1[i])>0) return 1;
                ++i;
            }
        }
        
        
        return 0;
        
    }
};