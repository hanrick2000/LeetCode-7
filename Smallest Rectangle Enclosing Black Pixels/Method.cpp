//An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
//
//For example, given the following image:
//
//[
//  "0010",
//  "0110",
//  "0100"
//]
//and x = 0, y = 2,
//Return 6.

//这题思路只要找到上下左右边界的最大值即可。DFS方法不说了，估计会超时。  假设我们要最左边的一条有黑点的列，我们可以从0到x列开始二分查找， 如果mid 那一列有黑点，就在左半边找，否则在右半边找。
//耗时：mlogn + nlogm .


class Solution {
public:

    bool columnALLWhite(vector<vector<char>>& image, int y) {
        
        for(int i = 0; i < image.size(); ++i) {
            if(image[i][y] == '1') return false;
        }
        
        return true;
    }
    
    bool rowALLWhite(vector<vector<char>>& image, int x) {
        
        for(int i = 0; i < image[0].size(); ++i) {
            if(image[x][i] == '1') return false;
        }
        
        return true;
    }

    int minArea(vector<vector<char>>& image, int x, int y) {
        
        int left, right, up, down, p = 0, q = y;
        
        while(p<q) {
            int c = (q-p)/2 + p;
            
            if(columnALLWhite(image,c)) {
                p = c + 1;
            }
            
            else {
                q = c;
            }
        }
        
        left = p, p = y, q = image[0].size()-1;
        
        while(p < q) {
            int c = (q-p-1)/2 +p+1;
            
            if(columnALLWhite(image,c)) {
                q = c - 1;
            }
            
            else {
                p = c;
            }
        }
        
        right = p, p = 0, q = x;
        
        while(p < q) {
            int c = (q-p)/2 + p;
            
            if(rowALLWhite(image,c)) {
                p = c + 1;
            }
            
            else {
                q = c;
            }
        }
        
        up = p, p = x, q = image.size()-1;
        
        while(p < q) {
            int c = (q-p-1)/2 +p+1;
            
            if(rowALLWhite(image,c)) {
                q = c - 1;
            }
            
            else {
                p = c;
            }
        }

        down = p;
   
        return (down-up+1)*(right - left+1);
        
    }
};