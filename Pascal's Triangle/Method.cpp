//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]

//杨辉三角，很简单，用加起来这个公式

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        
        for(int i = 0; i < numRows; ++i) {
            if(i == 0) res.push_back({1});
            else {
                vector<int> tmp = {1};
                for(int j = 0; j <res[i-1].size()-1;++j) {
                    tmp.push_back(res[i-1][j]+res[i-1][j+1]);
                }
                tmp.push_back(1);
                res.push_back(tmp);
            }
            
        }
        
        return res;
    }
};