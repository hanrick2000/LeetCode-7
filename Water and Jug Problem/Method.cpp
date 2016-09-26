//You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.
//
//If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
//
//Operations allowed:
//
//Fill any of the jugs completely with water.
//Empty any of the jugs.
//Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
//Example 1: (From the famous "Die Hard" example)
//
//Input: x = 3, y = 5, z = 4
//Output: True
//Example 2:
//
//Input: x = 2, y = 6, z = 5
//Output: False

这题仔细考虑一下可以知道它能够凑出的水量是两个杯子的最大公因数。所以只要Z是最大公因数的倍数且小于等于两个杯子的容积即可。

class Solution {
public:

    int gcd(int x, int y) {
        
        if (x < y) swap(x,y);
        
        while(y) {
            int r = x-y;
            x = max(x - y, y);
            y = min(y,r);
        }
        
        return x;
        
    }

    bool canMeasureWater(int x, int y, int z) {
        
        if(x<0||y<0) return false;
        
        int r = gcd(x,y);
        
        if(!r) return !z;

        return !(z%r)&&z <= x+y;
    }
};