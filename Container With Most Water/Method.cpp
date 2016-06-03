//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container.


//典型的2-pointer. 从两边开始，找到短的那条边，短边是瓶颈，需要提升才行, 哪边是短边，哪边的指针就继续找，直到找到更长的边为止。 
//以下两种写法大同小异：
//写法一：找到瓶颈，继续判断下一个面积
class Solution {
public:

    inline int min(int a, int b, bool &e) {
        if(a<b) {
            e = true;
            return a;
        }
        else {
            e = false;
            return b;
        }
    }

    int maxArea(vector<int>& height) {
        
        int p = 0,q = height.size()-1,max = 0;
        bool flag;
        
        while(p < q) {
            int temp = (q-p)*min(height[p],height[q],flag);
            max = max > temp?max:temp;
    
            if(flag) {
                p++;
            }
            
            else {
                q--;
            }
        }
        
        return max;
    }
};

//写法二，找到瓶颈，直到找到更长边再判断面积

class Solution {
public:

    inline int min(int a, int b, bool &e) {
        if(a<b) {
            e = true;
            return a;
        }
        else {
            e = false;
            return b;
        }
    }

    int maxArea(vector<int>& height) {
        
        int p = 0,q = height.size()-1,max = 0,bn = 0;
        bool flag;
        
        while(p < q) {
            bn = min(height[p],height[q],flag);
            int temp = (q-p)*bn;
            max = max > temp?max:temp;
    
            if(flag) {
                while(height[p]<=bn&&p<q) p++;
            }
            
            else {
                while(height[q]<=bn&&p<q) q--;
            }
        }
        
        return max;
    }
};