//Given two binary strings, return their sum (also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".

//很简单。必须熟练掌握！

class Solution {
public:
    string addBinary(string a, string b) {
        
        if(b.size() > a.size()) swap(a,b);
        
        int p = a.size()-1, q=b.size()-1,carry = 0;

        while(p>=0&&q>=0) {
            // a[p] = carry? b[q]==a[p]?'1':'0':b[q]==a[p]?'0':'1';
            int temp = a[p]-'0' + b[q] - '0' + carry;
            a[p] = (temp&1) + '0';
            carry = temp>1;
            --p;--q;
        }
        
        while(carry&&p>=0) {
            int temp = a[p]-'0' + carry;
            a[p] = (temp&1) + '0';
            carry = temp>1;
            --p;          
        }
        
        if(carry) a = "1" + a;
        
        
        return a;
        
    }
};