//Additive number is a string whose digits can form additive sequence.
//
//A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//
//For example:
//"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
//
//1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
//"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
//1 + 99 = 100, 99 + 100 = 199
//Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
//
//Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
//
//Follow up:
//How would you handle overflow for very large input integers?


//直接做follow up
//先通过大循环固定前两个数，然后构造一个“链式”函数，它接受first，second两个数，从字符串的1个点开始判断字符串的开头是不是等于这两个数的和，递归到达末尾才返回true。O（n^3)


class Solution {
public:
    string add(string num1, string num2) {  // 对两个string相加
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
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
        
        reverse(num1.begin(),num1.end());
        
        return num1;
    }
    
    
    bool isAdditiveNumberHelper(string &num, int start, string &first, string &second) {
        
        if(start+first.size()+second.size() == num.size()) return true;
        
        string answer = add(first,second);
        
        if(num.substr(start+first.size()+second.size(), answer.size()) != answer) return false;
        
        return isAdditiveNumberHelper(num, start + first.size(),second, answer);
        
    }
    
    
    bool isAdditiveNumber(string num) {
        
        string first;
        
        for(int i = 0; i < int(num.size())-2; ++i) {
            
            first += num[i];
            if(first.size()>1&&first[0] == '0') break;
            string second;
            for(int j = i+1; j < int(num.size())-1; ++j) {
                second += num[j];
                if(second.size()>1&&second[0] == '0') break;
                if(isAdditiveNumberHelper(num, 0,first, second)) return true;
            }
            
        }
        
        
        return false;
        
        
    }
};

