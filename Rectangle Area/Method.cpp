//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//
//Rectangle Area
//Assume that the total area is never beyond the maximum possible value of int.

//正确考虑清楚重叠面积怎么算。还有，一定要注意会不会溢出！！！！！

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int areaSum = (C-A)*(D-B) + (G-E)*(H-F);
        int a,b;
        if(min(H,D) <= max(B,F)) a = 0;
        else a = (min(H,D)-max(B,F));
        
        if((min(C,G)<=max(A,E))) b = 0;
        else b = (min(C,G)-max(A,E));
        
        
        return areaSum -a*b;
        
    }
};