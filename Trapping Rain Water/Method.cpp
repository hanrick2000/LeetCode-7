//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//For example, 
//Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//
//
//The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

//这题仔细观察，发现水位从0到塔尖位置是递增的，从尾部到塔尖也是递增的，所以从两边开始往中间走到塔顶水位是当前max, 面积要减掉塔高。

class Solution {
public:
    int trap(vector<int>& height) {
        
        int maxindex = -1, max = 0,res = 0;
        
        for(int i = 0; i < height.size(); ++i) {
            if(height[i] > max) {
                maxindex = i;
                max = height[i];
            }
        }
        
        max = 0;
        
        for(int i = 0; i <maxindex; ++i) {
            
            if(height[i] > max) {
                max = height[i];
            }
            else {
                res += max - height[i];
            }
        }
        
        max = 0;
        
        for(int i = height.size()-1; i > maxindex; --i) {
            
            if(height[i] > max) {
                max = height[i];
            }
            else {
                res += max - height[i];
            }
        }
        
        return res;
        
    }

    这个方法更好：和3D那道题思路一样，维持一个当前水位，从两边开始蔓延。3D里面那一个heap现在包含的就是两个值，max_left和max_right. 每一次选出小的那个进行蔓延，蔓延肯定是左边往右边蔓延，右边往左边蔓延。heap 的pop操作就是移动指针。双指针做。
    
    int trap(vector<int>& height) {

        int max_left = 0, max_right = 0, p = 0, q = height.size()-1, res = 0;
        
        while(p <= q) {
            if(max_left <= max_right) {
                if(height[p] < max_left) {
                    res += max_left - height[p];
                } else {
                    max_left = height[p];
                }
                ++p;
            } else {
                if(height[q] < max_right) {
                    res += max_right - height[q];
                } else {
                    max_right = height[q];
                }
                --q;
            }
        }
        return res;
    }
};