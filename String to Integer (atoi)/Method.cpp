//此方法 先剔除字符串前面的连续空格，然后允许出现一个可选的'+'或'-'，然后是数字，如果出现字符就直接忽略，可以返回当前所转换的数字了。
//注意溢出和符号
//O(n)时间 O(1)空间

class Solution {
public:
    
    inline bool isDigits(char c) {
        return c>='0' && c<= '9';
    }

    int myAtoi(string str) {
        
        int p = 0;
        while(p<str.size()&&str[p]==' '){++p;}
        
        if(p == str.size()) return 0;
        
        bool pos = true;
        
        if(str[p] == '-') {
            pos = false;
            p++;
        }
        
        else if(str[p] == '+') {
            p++;
        }
        
        else if (!isDigits(str[p])) {
            return 0;
        }
        
        int res = 0;
        int cut = pos?INT_MAX%10:INT_MAX%10+1;
        while(p<str.size()&&isDigits(str[p])) {
            if(res>INT_MAX/10||(res==INT_MAX/10&&str[p]-'0'>cut)) return pos?INT_MAX:INT_MIN;
            
            res = res*10 + str[p]-'0';
            p++;
        }
        
        return pos?res:-res;
        
    }
};