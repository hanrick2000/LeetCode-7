//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return the minimum cuts needed for a palindrome partitioning of s.
//
//For example, given s = "aab",
//Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.


//还是一样的，先快速构建出二维数组mymap,表示从s[i]到[j]是否为回文。
//然后这里有一个小技巧，设立一个一维count数组，count[i]表示从i到最后的最少分割数，那么count[i] = min(1+count[j+1]) i<=j<size() if dp[i][j] == true.  这样只要o(n^2)时空复杂度.


class Solution {
public:

    int minCut(string s) {
        vector<vector<bool>> mymap(s.size(),vector<bool>(s.size()));

        vector<string> cur;
        vector<vector<string>> res;
        
        for(int i = 0; i < s.size(); ++i) {
            mymap[i][i] = true;
        }
        
        for(int i = 0; i < int(s.size())-1; ++i) {
            mymap[i][i+1] = s[i]==s[i+1];
        }
        
        for(int i = 1; i < int(s.size())-1; ++i) {
            for(int k = 0; i+k+1 < s.size(); ++k) {
                if(!mymap[1+k][i+k]) continue;
                mymap[k][i+k+1] = s[k]==s[i+k+1];
            }
        }
        
        vector<int> count(s.size()+1);
        
        for(int i = s.size()-1; i>=0 ; --i) {
            count[i] = INT_MAX;
            for(int j = i; j < s.size(); ++j) {
                if(mymap[i][j]) {
                    count[i] = min(count[i],1+count[j+1]);
                }
            }
        }
        
        return count[0]-1;
        
        
        
    }
};

