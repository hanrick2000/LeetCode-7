//Write a program to find the n-th ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//
//Note that 1 is typically treated as an ugly number.
//
//Hint:
//
//The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
//An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
//The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
//Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).


//hint其实讲的很清楚，假设我们有了第k个ugly number, 第k+1个肯定是从之前的ugly number序列里面*2,*3或*5找到的。 那么怎么维护呢，所以维持三个指针，p2,p3,p5,p2分别指向当前还未*2，*3，*5的ugly number的下标，然后每次求新的ugly number都要求这三个下标数*2,*3,*5的最小值，是最小的那个下标++， 如果遇到一样，都一起++。




class Solution {
public:
    
    int getMin(int &p2, int &p3, int &p5, vector<int> &res) {
        
        int mini = min(min(res[p2]*2, res[p3]*3),res[p5]*5); 
        
        if(res[p2]*2 == mini) {
            ++p2;
        }
        if(res[p3]*3 == mini) {
            ++p3;
        }
        if(res[p5]*5 == mini) {
            ++p5;
        }
        
        return mini;
        
    }

    int nthUglyNumber(int n) {
        
        int p2 = 0, p3 = 0, p5 = 0;
        
        vector<int> res = {1};
        
        for(int i = 1; i < n; ++i ) {
            res.push_back(getMin(p2,p3,p5,res));
        }
        
        return res.back();
        
    }
};