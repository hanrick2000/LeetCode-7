//Given two numbers represented as strings, return multiplication of the numbers as a string.
//
//Note:
//The numbers can be arbitrarily large and are non-negative.
//Converting the input string to integer is NOT allowed.
//You should NOT use internal library such as BigInteger.

//思路是很简单，直接模拟手算方法。需要注意的是：
//1) 乘0  
//2) 从数的最右边开始算起 所以省的麻烦可以用reverse 两个string再做


class Solution {
public:

    string multiplySingle(char &digits1, string &num2) { //一个数字乘一个字符串

        int cflag = 0;
        string s;
        
        for(int i = 0; i < num2.size(); ++i ) {
            int temp = (num2[i]-'0')*(digits1-'0')+cflag;
            cflag = temp/10;
            s.push_back(temp%10+'0');
        }
        
        if(cflag) s.push_back(cflag+'0');
        
        return s;
    }
    
    string add(string num1, string &num2) { //两个字符串相加
        if(num1.size() < num2.size()) num1.swap(num2);
        int cflag = 0;
        int i = 0;

        for(; i < num2.size(); ++i) {
            int temp = (num2[i] - '0')+(num1[i]-'0')+cflag;
            cflag = temp/10;
            num1[i] = temp%10 + '0';
        }
        
        while(cflag&&i<num1.size()) {
            int temp = num1[i]-'0'+cflag;
            cflag = temp/10;
            num1[i++] = temp%10 + '0';
        }
        
        if(cflag) num1.push_back(cflag+'0');
        
        return num1;
    }

    string multiply(string num1, string num2) {
        
        if(num1 == "0" || num2 == "0") return "0";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string s = "0";
        
        for(int i = 0; i < num1.size(); ++i) {
            if(num1[i] == '0') continue;
            string temp = multiplySingle(num1[i],num2);
            temp = string(i,'0') + temp;
            s = add(s,temp);
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};