//Given a non-negative number represented as an array of digits, plus one to the number.
//
//The digits are stored such that the most significant digit is at the head of the list.

//很简单。
    
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int flag = 1, i = digits.size()-1;
        
        while(flag&&i>=0) {
            int temp = digits[i] + flag;
            flag = temp/10;
            digits[i--] = temp%10;
        }
        
        if(i<0&&flag) {
            digits.insert(digits.begin(),flag);
        }
        return digits;

    }
};