//此方法空间复杂度O(1)，直接在原string 上改。思路还是和以前一样，不过用另一个指针j表示扫描到i时，其等效的path是啥，由于等效path不会长于原path，所以可以放心的修改j之前的字符，最后返回path[0:j]的子串即可。

class Solution {
public:
    string simplifyPath(string path) {
        
        path += '/';
        string pre = "#";
        int j = 1;
        for(int i = 0; i < path.size(); ++i) {
            if(path[i] == '/') {
                if(pre == ""||pre == "."||pre == "#") {
                    pre = "";
                    continue;
                }
                if(pre=="..") {
                    int k = 1;
                    while(j>1&&k) {
                        --j;
                        if(path[j-1] == '/') {
                            --k;
                        }
                    }
                }
                
                if(pre!= "..") {
                    
                    for(int i = 0; i < pre.size(); ++i) {
                        path[j++] = pre[i];
                    }
                    path[j++] = '/';
                }
                
                pre = "";
            }
            
            else {
                pre+=path[i];
            }
        }
        if(j>1) --j;
        
        
        
        return path.substr(0,j);
    }
};