//Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
//
//Example:
//Given "bcabc"
//Return "abc"
//
//Given "cbacdcbc"
//Return "acdb"

//贪心法思路，从头开始，找到第一个不重复的字符，说明这个字符一定要出现在结果里，那么从这个字符（包括）之前找到最小的字符，加到结果里，然后把这个最小字符之后的该字符全部删掉，下一次递归的对该最小字符的后面的子串进行。
    
//要熟练使用hash表。删除字符为了节省时间可以用其它字符代替，并且更新hash表。  O(k * n) 其中k为字符串中唯一字符的个数，n为字符串的长度

class Solution {
public:
    string removeDuplicateLetters(string s) {

        string res;
        
        vector<int> hash(26,0);
        
        for(int i = 0; i < s.size(); ++i)  hash[s[i]-'a']++;
        
        int p = -1;
        
        while(++p < s.size()) {

            char mini = '{';
            int index = p;
            
            for(int i = p; i < s.size(); ++i) {
                
                if(s[i] == 'A') continue;
                
                --hash[s[i]-'a'];

                if(s[i] < mini) {
                    mini = s[i];
                    index = i;
                }
                
                if(hash[s[i]-'a']==0) {
                    
                    res += mini;
                    p = index;
                   
                    int k = index;
                    
                    while(++k < s.size())  {
                        
                        if (s[k] == 'A') {   //忘加这句话害惨了。。。。
                            continue;
                        }
                        
                        if(k <= i) ++hash[s[k]-'a'];
       
                        if(s[k] == mini) {
                            
                            --hash[s[k]-'a'];
                            
                            s[k] = 'A';
                        }
                    }
                    
                    break;
                }
            }
            
        }
        
        return res;
        
    }

};