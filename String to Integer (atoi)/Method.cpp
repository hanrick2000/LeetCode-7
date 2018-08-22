//此方法 先剔除字符串前面的连续空格，然后允许出现一个可选的'+'或'-'，然后是数字，如果出现字符就直接忽略，可以返回当前所转换的数字了。
//注意溢出和符号
//O(n)时间 O(1)空间
//注意判断正负数溢出。。。
//if(!neg && res > (INT_MAX - str[i]+'0')/10) return INT_MAX;
//if(neg && -res < (INT_MIN + str[i] - '0')/10 ) return INT_MIN;

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
            if(res>INT_MAX/10||(res==INT_MAX/10&&str[p]-'0'>cut)) return pos?INT_MAX:INT_MIN;   //这句容易忘记了 pos的判断
            
            res = res*10 + str[p]-'0';
            p++;
        }
        
        return pos?res:-res;
        
    }
    
    int myAtoi(string str) {

        int res = 0;
        bool pos = true;
        int i = 0;
        bool conversed = false;
        
        while(i < str.size() && str[i] == ' ') ++i;
        
        if(i < str.size()) {
            if(str[i] == '-') {
                pos = false;
                ++i;
            }
            else if(str[i] == '+') {
                ++i;
            }
        }
        
        while(i < str.size()) {
            if(str[i]<'0' || str[i] > '9') return conversed? pos? res:-res : NO_CONVERSION;
            
            if(pos && res > (INT_MAX - (str[i] - '0'))/10) return INT_MAX;
                
            if(!pos && res > -((INT_MIN + (str[i]-'0'))/10)) return INT_MIN;
            
            res = 10*res + str[i++] - '0';
            conversed = true;
        }
        
        return pos? res:-res;
    }
};