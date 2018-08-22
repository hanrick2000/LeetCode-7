//Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
//
//Example:
//For num = 5 you should return [0,1,1,2,1,2].
//
//Follow up:
//
//It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
//Space complexity should be O(n).
//Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

这题一开始的做法是找到规律，， 求i有多少bit时，可以求i最高位那个1后面那几位表示的数的bit数+1.控制一个变量mask, 代表这一位为1表示的数。
所以dp[i] = dp[i-mask] + 1;
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        
        for(int i = 1, mask = 1; i <= num; ++i) {
            if(i == mask<<1) {
                mask<<=1;
            } 
            res[i] = res[i - mask] + 1;
        }
        return res;
    }

还有种屌比做法：dp[i] = dp[i & (i-1)] + 1   i & (i-1) 是去掉i最后一个1. 牛逼的很。
    vector<int> countBits(int num) {
        vector<int> cnt(num + 1, 0);
        
        for (int i = 1; i <= num; i++) {
            cnt[i] = cnt[i & (i - 1)] + 1;      // i & (i - 1) is i without lowest 1 bit
        }
        
        return cnt;
}