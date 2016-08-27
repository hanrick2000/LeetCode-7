//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.
//
//Note:
//Have you consider that the string might be empty? This is a good question to ask during an interview.
//
//For the purpose of this problem, we define empty string as valid palindrome.


//很简单，两指针从两边扫描，遇到非字母数字跳过，否则比较两字母是否相等，不考虑大小写。不要忘记指针移动。


class Solution {
public:

    bool isAlphanumeric(char c) {
        return c>='0'&&c<='9'||c>='a'&&c<='z'||c>='A'&&c<='Z';
    }
    
    void lower(char &c) {
        if(c>='A'&&c<='Z') c += 'a'-'A';
    }

    bool isPalindrome(string s) {
        int p = 0, q = s.size()-1;
        
        
        while(p<q) {
            if(!isAlphanumeric(s[p])) ++p;
            
            else if(!isAlphanumeric(s[q])) --q;
            
            else {
                lower(s[p]);
                lower(s[q]);
                if(s[p]!=s[q]) return false;
                ++p;
                --q;
            }

        }
        
        return true;
        
    }
};