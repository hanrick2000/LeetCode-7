//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//For example, given the following matrix:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 6.

//这题把每一行看做是求直方图最大面积，对n行进行计算，结果就有了，所以是O(n^2).

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        
        int top = -1;
        
        heights.push_back(0);
        
        vector<int> mystack(heights.size());
        
        int res = 0;
        
        for(int i = 0; i < heights.size(); ++i) {
       
            while(top >= 0 && heights[i] < heights[mystack[top]]) {
                    
                int index = mystack[top--];
                    
                res = max(res, heights[index] * (i - (top>=0?mystack[top]+1: 0)));
            }
                
            mystack[++top] = i;

        }

        return res;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(!matrix.size() || !matrix[0].size()) return 0;
        
        vector<int> heights(matrix[0].size());
        
        int res = 0;
        
        for(int i = 0; i < matrix.size(); ++i) {
            
            for(int j = 0; j < matrix[i].size(); ++j) {
                
                if(matrix[i][j] == '0') heights[j] = 0;
                
                else {
                    heights[j] += 1;
                }
                
            }
            
            res = max(res, largestRectangleArea(heights));
        }
        
        
        return res;
        
    }
};
