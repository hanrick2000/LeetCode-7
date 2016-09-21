//Write a program to find the nth super ugly number.
//
//Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
//
//Note:
//(1) 1 is a super ugly number for any given primes.
//(2) The given numbers in primes are in ascending order.
//(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

这题思路还是和ugly number一样，对所有的primes数组 控制一个指针，指针指向当前已经乘过primes的uglynumber的下标。每一次取出这k个指向的uglynumber的下标*相应primes的最小值即可。注意有还几个最小值，每一个指针都得++。
这里取出最小是用priority_queue实现的。 也可以线性扫描。

struct Node {
    int index; 
    int prime;
    int val;
    Node(int p): index(0),prime(p), val(p) {}
};

struct comparator{
    bool operator () (const Node&a, const Node&b) {
        return a.val > b.val;
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        vector<int> uglyLists(n);
        uglyLists[0] = 1;
        priority_queue<Node, vector<Node>, comparator> myheap;
        
        for(auto p : primes) {
            myheap.push(Node(p));
        }
        
        for(int i = 1; i < n; ++i) {
            int mini = myheap.top().val;
            uglyLists[i] = mini;
        
            while(myheap.top().val == mini) {
                Node tmp = myheap.top();
                myheap.pop();
                tmp.val = uglyLists[++tmp.index]*tmp.prime;
                myheap.push(tmp);
            }
        }
        
        return uglyLists.back();
    }
};

线性扫描。

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        vector<int> uglyLists(n,INT_MAX), pointers(primes.size(),0);
        
        uglyLists[0] = 1;

        for(int i = 1; i < n; ++i) {
            
            for(int j = 0; j < primes.size(); ++j) uglyLists[i] = min(uglyLists[i], primes[j]*uglyLists[pointers[j]]);
            for(int j = 0; j < primes.size(); ++j) pointers[j] += primes[j]*uglyLists[pointers[j]] == uglyLists[i];
        }
        
        return uglyLists.back();
    }
};