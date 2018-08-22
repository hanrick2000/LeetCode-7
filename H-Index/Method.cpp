//Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
//
//According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
//
//For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.
//
//Note: If there are several possible values for h, the maximum one is taken as the h-index.
//
//Hint:
//
//An easy approach is to sort the array first.
//What are the possible values of h-index?
//A faster approach is to use extra space.

逆序排序，i=0开始与nums[i]比较，如果nums[i]比它小就退出循环返回i。

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        if(!citations.size()) return 0;
        
        sort(citations.begin(),citations.end(),greater<int>());
        
        int i = 0;
        
        for(; i < citations.size(); ++i) {
            
            if(citations[i] < i+1) {
                return i;
            }
        }
        
        return i++;
        
    }
};
    
    算了还是记从小到大排列吧

    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(),citations.end());

        for(int i = 0; i < citations.size(); ++i) {   // 找到第一个
            
            if(citations[i] >= citations.size() - i) {   
                return citations.size() - i;
            }
        }
        
        return 0;
        
    }



//还有一种O(n)的方法，类似于counting sort.记录每一个数出现的次数，最后从高位开始，依次累加，这样可以得到，大于等于i的个数。
    
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        if(!citations.size()) return 0;
        
        vector<int> count(citations.size()+1);
        
        for(auto x:citations) {
            if(x > citations.size()) ++count[citations.size()];
            else {
                ++count[x];
            }

        }
        
        if(count.back() >= citations.size()) return citations.size();
        
        for(int i = count.size()-2; i >= 0; --i) {
            count[i]= count[i] + count[i+1];
            
            if(count[i] >= i) return i;
            
        }
        return 0;
        
    }
};
