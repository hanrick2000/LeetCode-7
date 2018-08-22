//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//For example,
//Given:
//s1 = "aabcc",
//s2 = "dbbca",
//
//When s3 = "aadbbcbcac", return true.
//When s3 = "aadbbbaccc", return false.


//dp思路是这样的，把s1,s2当作二维数组的两维。从左上角开始，s1="" s2=""与s3=""匹配开始，1表示匹配，0表示不匹配。每次往下移动一格，表示拿s1[i-1]与s3[i+j-1]匹配，往右移动一格表示拿s2[j-1]与s3[i+j-1]匹配。
//最后看看右下角是否是1.但还没完，你得确定s3的长度得正好在右下角附近。

//    
//0 c d  s2
//a 1
//b
//s1

class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<bool>> opt(s1.size()+1,vector<bool>(s2.size()+1,false));
        
        opt[0][0] = true;
        
        for(int i = 0; i < opt.size(); ++i) {
            for(int j = 0; j < opt[0].size(); ++j) {
                if(!i&&!j) continue;
                
                if(!j) {
                    opt[i][j] = opt[i-1][j]&&s1[i-1]==s3[i+j-1];
                }
                
                else if(!i) {
                    opt[i][j] = opt[i][j-1]&&s2[j-1]==s3[i+j-1];
                }
                
                else {
                    opt[i][j] = opt[i-1][j]&&s1[i-1]==s3[i+j-1] || opt[i][j-1]&&s2[j-1]==s3[i+j-1];
                }
            }
        }
        
        return opt.back().back()&&s1.size()+s2.size()==s3.size();
        
        
    }
};

