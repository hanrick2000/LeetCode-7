//Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
//
//Hint:
//
//Expected runtime complexity is in O(log n) and the input is sorted.

经提示才知道要用二分法，可是该问题相当于如何找在一个递增数列中找到最后一个负数？要用一个last记录。

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int p = 0, q = citations.size()-1;
        
        int last = -1;
        
        while(p<=q) {
            
            int c = (p+q)/2;
            
            if(citations[c] - (int(citations.size())-c) >= 0) {
                q = c-1;
            }
            
            else {
                last = c;
                p = c+1;
            }
        }
        
        return citations.size() - last - 1;
        
    }
};

忽然想起来  也有findleft版本的binary search.直接找到第一个正数那样，关键是要处理好如何不死循环。
    
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        if(!citations.size()) return 0;
        
        int p = 0, q = int(citations.size()-1);
        
        while(p<q) {
            
            int c = (p+q)/2;
            
            if(citations[c] - (int(citations.size())-c) < 0) {
                p = c+1;
            }
            
            else {
                
                q = c;
            }
        }
        
        p = citations[p] - (int(citations.size())-p) >=0 ? p: p+1;
        
        return citations.size() - p;
        
    }
};