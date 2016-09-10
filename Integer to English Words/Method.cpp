//Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
//
//For example,
//123 -> "One Hundred Twenty Three"
//12345 -> "Twelve Thousand Three Hundred Forty Five"
//1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
//Hint:
//
//Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
//Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
//There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)

分成一千一千的来。中间的一千里面0不能输出"zero",空格也不能忘记

class Solution {
public:

    string lessthousand(int num) {
        vector<string>  a1= {"Zero", "One" ,"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"},
            a2 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        
        if(num < 20) return a1[num];
        
        if(num < 100) {
            string res;
            res += a2[num/10-2];
            if(num%10) {
                res += " " + a1[num%10];
            }
            
            return res;
        }
        
        string res;
        
        res += a1[num/100] + " Hundred";
        
        num -= num/100*100;
        
        if(num < 20) {
            if(num)
                res += " " +a1[num];
            return res;
            
        }
        
        res += " " + a2[num/10-2];
        if(num%10) {
            res += " " + a1[num%10];
        }
            
        return res;
        
    }


    string numberToWords(int num) {
        
        if(num < 1000) return lessthousand(num);
        
        if(num < 1000000) {
            string res;
            
            res += lessthousand(num/1000) + " " + "Thousand";
            
            if(num%1000) {
                res += " " + lessthousand(num%1000);
            }
            
            return res;
        }
        
        if(num < 1000000000) {
            string res;
            
            res += lessthousand(num/1000000) + " " + "Million";
            
            num= num - num/1000000*1000000;
            if(num/1000) res += " " + lessthousand(num/1000) +  " " + "Thousand";
            
            if(num%1000) {
                res += " " + lessthousand(num%1000);
            }
            
            return res;
        }
        
        string res;
        
        res += lessthousand(num/1000000000) + " " + "Billion";
        
        num= num - num/1000000000*1000000000;
        
        if(num/1000000) res += " " + lessthousand(num/1000000) + " " + "Million";
        
        num= num - num/1000000*1000000;
        if(num/1000) res += " " + lessthousand(num/1000) + " " + "Thousand";
            
        if(num%1000) {
            res += " " + lessthousand(num%1000);
        }
                
        return res;

    }
};
