//Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.
//
//Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).
//
//You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.
//
//Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.


//很简单的思想，任意挑两个人A,B查询一次，如果A认识B,那么A不是名人，否则B不是名人，所以每次询问一次都会有一个人被排除，n-1次循环后，只剩下一个人，只要看看这个人是不是名人即可。注意检查是要判断他是不是不认识所有人且所有人是不是都认识他。

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        
        int A = 0, B = 1;
        
        do {
            bool flag = knows(A,B);
            if(flag) A = B;
            
            ++B;
            
        }while(B<n);
        
        for(int i = 0; i < n;++i) {
            if(A!=i) {
                if(knows(A,i)||!knows(i,A)) return -1;
            }
        }
        return A;
        
    }
};