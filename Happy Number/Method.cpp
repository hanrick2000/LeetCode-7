//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
//Example: 19 is a happy number
//
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1


class Solution {
public:
    bool isHappy(int n) {
        
        bool visited[1000] = {false};   //  最大也就10*10*10 因为int_max 只有9位
        
        while(n!=1) {

            int sum = 0;
            
            while(n) {
                int gewei = (n%10);
                sum += gewei*gewei;
                n/=10;
            }
            
            n = sum;
            if(visited[n]) return false;
            
            visited[n] = true;
            
        }
        
        return true;
        
    }
};