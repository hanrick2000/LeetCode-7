//Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
//
//Examples: 
//"123", 6 -> ["1+2+3", "1*2*3"] 
//"232", 8 -> ["2*3+2", "2+3*2"]
//"105", 5 -> ["1*0+5","10-5"]
//"00", 0 -> ["0+0", "0-0", "0*0"]
//"3456237490", 9191 -> []

//因为要输出所有可能的情况，必定是用深度优先搜索。问题在于如何将问题拆分成多次搜索。加减法很好处理，每当我们截出一段数字时，将之前计算的结果加上或者减去这个数，就可以将剩余的数字字符串和新的计算结果代入下一次搜索中了，直到我们的计算结果和目标一样，就完成了一次搜索。然而，乘法如何处理呢？这里我们需要用一个变量记录乘法当前累乘的值，直到累乘完了，遇到下一个加号或减号再将其算入计算结果中。这里有两种情况:
//
//乘号之前是加号或减号，例如2+3*4，我们在2那里算出来的结果，到3的时候会加上3，计算结果变为5。在到4的时候，因为4之前我们选择的是乘号，这里3就应该和4相乘，而不是和2相加，所以在计算结果时，要将5先减去刚才加的3得到2，然后再加上3乘以4，得到2+12=14，这样14就是到4为止时的计算结果。
//另外一种情况是乘号之前也是乘号，如果2+3*4*5，这里我们到4为止计算的结果是14了，然后我们到5的时候又是乘号，这时候我们要把刚才加的3*4给去掉，然后再加上3*4*5，也就是14-3*4+3*4*5=62。这样5的计算结果就是62。
//因为要解决上述几种情况，我们需要这么几个变量，一个是记录上次的计算结果currRes，一个是记录上次被加或者被减的数prevNum，一个是当前准备处理的数currNum。当下一轮搜索是加减法时，prevNum就是简单换成currNum，当下一轮搜索是乘法时，prevNum是prevNum乘以currNum。

class Solution {
public:
    
    
    void dfs(string &num, int target, long long curRes, long long prevNum, int start, string cur, vector<string> &res) {

        long long curNum = 0;
        string cur2 = cur;
        for(int i = start; i < num.size(); ++i) {
            if(num[start] == '0' && i > start) break;
            
            curNum = curNum*10 + num[i] - '0';
      
            long long c, p;
            if(cur2 == "" || cur2.back() == '+') {
                c = curRes + curNum;
                p = curNum;
            }
            
            else if(cur2.back() == '-') {
                
                c = curRes - curNum;
                p = -curNum;
            }
            
            else if(cur2.back() == '*') {
                
                c = curRes - prevNum + curNum*prevNum;
                p =  curNum*prevNum;
            }
           
            cur+=num[i];
            
            if(i == num.size()-1 && c == target)  {
                res.push_back(cur);
                return;    
            }
       
            dfs(num, target, c, p, i+1, cur + '+', res);
            
            dfs(num, target, c, p, i+1,cur + '-', res);
            
            dfs(num, target, c, p, i+1, cur + '*', res);
            
        }
        return ;
        
    }

    vector<string> addOperators(string num, int target) {
        
        vector<string> res;
        
        dfs(num, target, 0, 0, 0,"", res);

        return res;
    }
};