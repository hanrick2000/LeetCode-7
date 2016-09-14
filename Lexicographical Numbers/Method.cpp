//Given an integer n, return 1 - n in lexicographical order.
//
//For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
//
//Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.


//这题我只会recursion, 让a从1开始迭代进入，每一次迭代如果a小于n，就push_back，否则return，然后尝试迭代a*10... 回来之后再尝试迭代a+1,不过仅当该number末尾不是9。时间是O(n) ,空间使用了O(logn), 90%的节点使用了2分，10%的节点使用1分。   


class Solution {
public:

    void dfs(vector<int> &res, int a, int n) {
        
        if(a > n) return;
        
        res.push_back(a);
        dfs(res, a*10,n);
        
        if(a%10!=9) dfs(res,a+1,n);

    }

    vector<int> lexicalOrder(int n) {
        
        vector<int> res;
        dfs(res,1,n);

        return res;
        
    }
};
