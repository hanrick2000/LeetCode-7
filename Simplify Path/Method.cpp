//Given an absolute path for a file (Unix-style), simplify it.
//
//For example,
//path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"
//click to show corner cases.
//
//Corner Cases:
//Did you consider the case where path = "/../"?
//In this case, you should return "/".
//Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//In this case, you should ignore redundant slashes and return "/home/foo".


//典型的字符串处理，以扫描到'/'，作为判断，然后存到vector里面。


class Solution {
public:
    string simplifyPath(string path) {
        
        path+='/';
        vector<string> token;
        
        string pre = "/";
        for(int i = 0; i < path.size(); ++i) {
            if(path[i] == '/') {
                if(pre == ""||pre == ".") {
                    pre = "";
                    continue;
                }
                if(pre==".." && token.size() > 1) token.pop_back();
                if(pre!= "..") token.push_back(pre);
                
                pre = "";
            }
            
            else {
                pre+=path[i];
            }
        }
        string res;
        
        for(auto &x: token) {
            if(x == "/") res += '/';
            else res += x+'/';
        }
        if(res.size()>1) res.pop_back();
        return res;
    }
};