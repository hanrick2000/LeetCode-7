// 匹配s和p，对于p来说 有四种可能
// 1) 空串： s也要空串才匹配
// 2) 一个字符， s也要一个字符，并且两个字符一样或p的字符是'.'
// 3) 至少两个字符，第二个字符不是'*', 第一个字符得匹配，然后在递归处理s[1:] 和 p[1:]
// 4) 至少两个字符，第二个字符是'*', 然后如果s[0]开始的几个字符如果都可以和p[0]匹配，递归匹配，也可以不匹配s[0]。
// 递推公式：
//  dp[i][j] = i) p[j+1]!='*' IF s[i] == p[j] =dp[i+1][j+1] ELSE false;
//  ii)p[j+1]=='*' IF s[i] == p[j]||p[j] == '.' search dp[i][j+2] ... dp[i+1][j+2]... dp[i+2][j+2] 即++i直到使得上述条件不成立。找到一个true即可
//                  ELSE = dp[i][j+2]
//
//
// 速度奇慢无比，为啥呢？频繁应用了substr 这个函数是一件非常愚蠢的事情。
class Solution {
public:
    bool isMatch(string s, string p) {
        
        if(p == "") return s == ""; 
        
        if(p.size()<2) {
            if(s == "") return false;
            if(s.size()>1) return false; 
            
            return p[0] == s[0]||p[0] == '.';
        }
        
        if(p[1] != '*') {
            if(s == "") return false;
            if(p[0] == s[0]||p[0] == '.') {
                return isMatch(s.substr(1,s.size()-1),p.substr(1,p.size()-1));
            }
            return false;
        }
        
        int i = 0;
        while(i<s.size()&&(s[i] == p[0]||p[0] == '.')) {
            if(isMatch(s.substr(i+1,s.size()-1-i),p.substr(2,p.size()-2)))
                return true;
            i++;
        }

        return isMatch(s.substr(0,s.size()),p.substr(2,p.size()-2));
        
    }
};

//可以修改原函数的参数，用i, j 两个下标指针以及s 和 p 作为参数，即使用s,i,p,j表示  s.substr(i,s.size()-i), p.substr(j,p.size()-j)。显著下降时间复杂度！修改后的代码为：
//时间 exponential ,
class Solution {
public:
    bool isMatch(string s, string p) {
        return backtracking(s,0,p,0);
    }
    
    bool backtracking(string &s, int i, string &p, int j) {
        
        if(j==p.size()) return i == s.size();
        
        if(j==p.size()-1) {
            if(i == s.size()) return false;
            return (s[i] == p[j] || p[j] == '.')&&i==s.size()-1;    
        }
        
        if(p[j+1]!='*') {
            if(i == s.size()) return false;
            if(s[i] == p[j] ||p[j] == '.') return backtracking(s,i+1,p,j+1);
            return false;
        }
        
        if(backtracking(s,i,p,j+2)) return true;
        
        while(i<s.size()&&(s[i]==p[j] || p[j]=='.')) {
            if(backtracking(s,++i,p,j+2)) return true;   
        }
        return false;
        
    }
};

//可以想象  计算一个例子，同样一堆参数 i,j估计会在递归时重复计算，果断用memoization. 用一个map来保存。时间复杂度为O(m*n)m,n为s和p的长度，空间为O(m*n)。代码如下：
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<int> map((s.size()+1)*(p.size()+1),-1);
        return backtracking(s,0,p,0,map);
    }
    
    bool backtracking(string &s, int i, string &p, int j, vector<int> &map) {
        int index = i*(p.size()+1)+j;
        if(map[index]!=-1) return map[index];
        
        if(j==p.size()) {
            map[index] = i == s.size();
            return map[index];
        }

        if(j==p.size()-1) {
            if(i == s.size()) {
                map[index] = false;
                return false;
            }
            map[index] = (s[i] == p[j] || p[j] == '.')&&i==s.size()-1;
            return map[index];
        }
        
        if(p[j+1]!='*') {
            if(i == s.size()) {
                map[index] = false;
                return false;
            }
            
            if(s[i] == p[j] ||p[j] == '.') {
                map[index] = backtracking(s,i+1,p,j+1,map);
                return map[index];
            }
            map[index] = false;
            return false;
        }

        if(backtracking(s,i,p,j+2,map)) {
            map[index] = true;
            return true;
        }
        
        while(i<s.size()&&(s[i]==p[j] || p[j]=='.')) {
            if(backtracking(s,++i,p,j+2,map)) {
                map[index] = true;
                return true;
            }
        }
        
        map[index] = false;
        return false;
    }
};