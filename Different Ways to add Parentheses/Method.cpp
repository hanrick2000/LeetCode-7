//Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
//
//
//Example 1
//Input: "2-1-1".
//
//((2-1)-1) = 0
//(2-(1-1)) = 2
//Output: [0, 2]
//
//
//Example 2
//Input: "2*3-4*5"
//
//(2*(3-(4*5))) = -34
//((2*3)-(4*5)) = -14
//((2*(3-4))*5) = -10
//(2*((3-4)*5)) = -10
//(((2*3)-4)*5) = 10
//Output: [-34, -14, -10, -10, 10]


思想很简单，devide conquer 外加memo. 具体来说首先把字符串弄成vector符号表，存放操作数和操作符。然后我们计算某一个表达式有多少种解法时，需要把表达式从中间切开，对每一个子问题进行递归。记住要memo.

class Solution {
    
    
public:


    vector<int> diffWaysToComputeHelper(int start, int end, vector<string> &token, vector<vector<vector<int>>> &mem) {
        
        if(mem[start][end].size()) return mem[start][end];
        
        
        
        vector<int> res;
        
        if(start == end) {
            res.push_back(stoi(token[start]));
            mem[start][end] = res;
            
            return res;
        }
        
        
        
        for(int i = start;i < end ;i+=2) {
            vector<int> tmp1 = diffWaysToComputeHelper(start, i, token, mem);
            vector<int> tmp2 = diffWaysToComputeHelper(i+2, end, token, mem);
            
            for(int j = 0; j < tmp1.size(); ++j) {
                for(int k = 0; k < tmp2.size(); ++k) {
                    if( token[i+1] == "+" ) res.push_back(tmp1[j]+tmp2[k]);
                    if( token[i+1] == "-" ) res.push_back(tmp1[j]-tmp2[k]);
                    if( token[i+1] == "*" ) res.push_back(tmp1[j]*tmp2[k]);
                }
            }
        }
        
        mem[start][end] = res;
        
        return res;
        
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<string> token;
        string tmp;
        for(int i = 0; i < input.size(); ++i) {
            if(input[i]>='0' && input[i]<='9') {
                tmp+=input[i];
            }
            
            else {
                token.push_back(tmp);
                string t;
                t+=input[i];
                token.push_back(t);
                tmp = "";
            }
        }
        token.push_back(tmp);
        
        // for(int i = 0; i < token.size(); ++i) {
        //     cout<<token[i]<<endl;
        // }
        
        vector<int> res;
        
        vector<vector<int>> tm(token.size());
        vector<vector<vector<int>>> mem(token.size(),tm);
        
        
        
        return diffWaysToComputeHelper(0,token.size()-1,token,mem);
        
    }
};