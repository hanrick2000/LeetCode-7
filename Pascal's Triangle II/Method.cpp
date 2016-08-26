//Given an index k, return the kth row of the Pascal's triangle.
//
//For example, given k = 3,
//Return [1,3,3,1].
//
//Note:
//Could you optimize your algorithm to use only O(k) extra space?


//关键是只能用O(k)的空间，所以第k项得在k-1项上修改。


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> tmp;
        
        for(int i = 0; i <= rowIndex; ++i) {
            
            int pre = 1;            //pre 记录了k-1项第[j-1]项的数
            for(int j = 1; j < tmp.size(); ++j) {
                tmp[j] += pre;  //更新j项
                pre = tmp[j] - pre;  //检索回j项原本的数。
            }
            tmp.push_back(1);
            
        }
        return tmp;
        
    }
};