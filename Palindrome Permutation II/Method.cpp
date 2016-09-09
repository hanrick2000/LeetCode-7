//Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.
//
//For example:
//
//Given s = "aabb", return ["abba", "baab"].
//
//Given s = "abc", return [].
//
//Hint:
//
//If a palindromic permutation exists, we just need to generate the first half of the string.
//To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.


//第一反应：用hash表记录每个字符出现次数。 dfs,每一次进去遍历所有有次数的字符，左右两边各加上这个字符，然后修改hashmap，然后继续递归，注意回溯！
    
    
class Solution {
public:

    void dfs(string &cur, vector<int> &a, vector<string> &res) {
        
        bool flag = false;
        for(int i = 0; i < 128; ++i) {
            if(a[i]) {
                flag = true;
                break;
            }
        }
        
        
        if(!flag) {
            res.push_back(cur);
            return;
        }
        
        
        for(int i = 0; i < 128; ++i) {
            if(a[i]) {
    
                cur.insert(cur.begin(), char(i));

                cur+=char(i);
                
                a[i]-=2;
                
                dfs(cur,a,res);
                
                cur = cur.substr(1,cur.size()-2);

                a[i]+=2;
            }
        }
        
        return;
        
    }
    
    vector<string> generatePalindromes(string s) {
        
        vector<int> a(128);
        
        for(int i = 0; i < s.size(); ++i) {
            ++a[s[i]];
        }
        
        int single = 0;
        string odd;
        
        for(int i = 0; i <128; ++i) {
            if(a[i]%2) {
                ++single;
                odd += char(i);
                --a[i];
            }
            if(single > 1) return {};
        }
        
        vector<string> res;
       
        
        dfs(odd, a, res);
        
        return res;
        
        
    }
};
