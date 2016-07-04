//The set [1,2,3,…,n] contains a total of n! unique permutations.
//
//By listing and labeling all of the permutations in order,
//We get the following sequence (ie, for n = 3):
//
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
//Given n and k, return the kth permutation sequence.
//
//Note: Given n will be between 1 and 9 inclusive.


//这题一开始我以为用dfs按照12345...9的初始情况，用生成排序的做法正常递归，得到的结果顺序就是题意要求的顺序，后来一测试不是，例如n=3 第5个排列 123 产生是  1和3换后递归  即  321 会先出现在312. 后来只能把3插入到最前面这么处理，这样的逻辑是对的，但是要用掉O(n!)时间。超时。。。
//
//用点数学的做法是将k用类似于十进制数那样的阶乘和来表示，如15 = 2*3!+1*2!+1*1!. 为了统一，我们让k从0开始计算。即第一个排列就相当于原始的排列不动。  然后对于1234， 如果是最后一个排列（15），我们先处理2*3!, 首先3！，用i指向最高位，最高位后2位与i位的数对换，得到3214,然后将最高位后面的部分排序，得到3124, 然后处理1*2!, i指向次高位，次高位后一位与之对换再排序，得到3214， 然后再处理1*1!, 得到3142.
//耗时O(n). 排序啥的都可以忽略，因为最多就9个数。

class Solution {
public:

    string getPermutation(int n, int k) {
                
        --k;
        vector<int> dic(9);
        
        int pr = 1,i=1;
        
        string res,v;
        for(int i = 1; i <= n; ++ i) {
            v+= i + '0';
        }
        
        while(pr*i <= k) {
            pr*=i;
            dic[i++] = pr;
        }
        
        --i;

        while(k) {
            
            int temp = dic[i];
            dic[i] = k / dic[i];
            k -= temp* dic[i];

            swap(v[n-i-1+dic[i]],v[n-i-1]);            
            sort(v.begin()+n-i,v.end());
            
            --i;
        }
        
        return v;
    }
};