//Description:
//
//Count the number of prime numbers less than a non-negative number, n.


//用那个吊比方法。o(n loglogn). 先假设全部数都是质数。从2开始 每一次把4，6，8...划掉，然后找到下一个质数(3).把6,9,12...划掉。。。一直到根号(n), 因为后面的合数肯定都被划掉了，每次化掉一个和数，--次数，最后剩下的次数就是素数的个数。


class Solution {
public:
    int countPrimes(int n) {
        
        if(n<3) return 0;
        
        bool notPrime[n] = {false};
        
        int count = n-2;
        for(int i = 2; i*i< n; ++i) {
            if(!notPrime[i]) {
                
                for(int j = i*i; j < n; j+=i) {
                    if(!notPrime[j]) {
                        --count;
                        notPrime[j] = true;
                    }

                }
            }
        }
        
        return count;
    }
};