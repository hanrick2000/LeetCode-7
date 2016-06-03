//Given an integer, convert it to a roman numeral.

//Input is guaranteed to be within the range from 1 to 3999.

//很简单把每个数位都转换成罗马数字，拼起来，也可以用表的方式做

class Solution {
public:
    
    string gewei(int digit) {
        switch(digit){
            case 1: return "I";
            case 2: return "II";
            case 3: return "III";
            case 4: return "IV";
            case 5: return "V";
            case 6: return "VI";
            case 7: return "VII";
            case 8: return "VIII";
            case 9: return "IX";
            default:return "";
        }
    }
    
    string shiwei(int digit) {
        switch(digit){
            case 1: return "X";
            case 2: return "XX";
            case 3: return "XXX";
            case 4: return "XL";
            case 5: return "L";
            case 6: return "LX";
            case 7: return "LXX";
            case 8: return "LXXX";
            case 9: return "XC";
            default:return "";
        }
    }
    
    string baiwei(int digit) {
        switch(digit){
            case 1: return "C";
            case 2: return "CC";
            case 3: return "CCC";
            case 4: return "CD";
            case 5: return "D";
            case 6: return "DC";
            case 7: return "DCC";
            case 8: return "DCCC";
            case 9: return "CM";
            default:return "";
        }
    }
    
    string qianwei(int digit) {
        switch(digit){
            case 1: return "M";
            case 2: return "MM";
            case 3: return "MMM";
            default:return "";
        }
    }

    string intToRoman(int num) {
        int qian = num/1000, bai = (num/100)%10, shi = (num/10)%10, ge = num%10;
        
        return qianwei(qian) + baiwei(bai) + shiwei(shi) + gewei(ge);
    }
};