//Assume you have an array of length n initialized with all 0's and are given k update operations.
//
//Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
//
//Return the modified array after all k operations were executed.
//
//Example:
//
//Given:
//
//    length = 5,
//    updates = [
//        [1,  3,  2],
//        [2,  4,  3],
//        [0,  2, -2]
//    ]
//
//Output:
//
//    [-2, 0, 3, 5, 3]
//Explanation:
//
//Initial state:
//[ 0, 0, 0, 0, 0 ]
//
//After applying operation [1, 3, 2]:
//[ 0, 2, 2, 2, 0 ]
//
//After applying operation [2, 4, 3]:
//[ 0, 2, 5, 5, 3 ]
//
//After applying operation [0, 2, -2]:
//[-2, 0, 3, 5, 3 ]
//Hint:
//
//Thinking of using advanced data structures? You are thinking it too complicated.
//For each update operation, do you really need to update all elements between i and j?
//Update only the first and end element is sufficient.
//The optimal time complexity is O(k + n) and uses O(1) extra space.

//这题思路屌的一逼。如果我们想要在[a,b]都加上x, 那么我们可以在a上加x,b+1上加-x.这样最后计算一个前缀和就可以发现[a,b]都加上了x, b+1开始不变（加了x,减了x）。
//所以前k次只要这么标记一下，最后扫描一遍字符串求个前缀和即可。

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        
        vector<int> res(length);
        
        for(int i = 0; i < updates.size(); ++i) {
            res[updates[i][0]] += updates[i][2];
            
            if (updates[i][1] + 1 < length)  res[updates[i][1]+1] -= updates[i][2];   //这个if条件很容易忘啊
        }
        
        for(int i = 1; i < length; ++i) {
            res[i]+=res[i-1];
        }
        
        return res;
        
    }
};