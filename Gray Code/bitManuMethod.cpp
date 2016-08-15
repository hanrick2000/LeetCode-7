//这道题最屌的解法： 

//二进制码->格雷码（编码）：从最右边一位起，依次将每一位与左边一位异或（XOR），作为对应格雷码该位的值，最左边一位不变（相当于左边是0）；这一步可以通过该数xor它本身向左移位的结果。


class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> res;
        
        int k = 1<<n;
               
        for(int i = 0; i < k; ++i) {
            res.push_back(i^(i>>1));
        }
        
        return res;
        
    }
};