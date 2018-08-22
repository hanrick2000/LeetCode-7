// 这个方法是我做了jump game II 时才想到的，先来看每一组成功跳到的例子，我们可以发现，如果把nums[i] 看成起点为i,长度为nums[i]的区间。那么一个完整的跳跃戏略相当于一系列的区间，覆盖[0,n-1]。  那么这题什么情况会到不了终点呢？ 很显然就是 这一系列区间会中途“断掉”，就是存在某一个nums[i],使得前面所有的nums[0...i-1]的终点都够不着区间i的起点。 因此，我们选择的跳跃方式是从区间0出发，顺序往下查找，对于所有那些起点在0 到 nums[0]间的区间，找终点位置最大值的区间，该区间的起点就是下一步跳到的位置。如果找不到这样的区间，而终点又没到，那就失败，否则我们继续找，直到跳到终点。



class Solution {
public:

    bool canJump(vector<int>& nums) {
        
        if(nums.size() == 1) return true;
        
        int pre = 0;
        
        int maxi = -1,index = -1;
        
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[pre]+pre >=  nums.size()-1) break; //上次找到的点能一步跳到终点  退出循环就成功！
            if(i<=nums[pre]+pre) {   // i在上次找到的点的可达范围内
                if(nums[i]+i > maxi) {  //如果i点终点更远，更新max 和 index
                    maxi = nums[i]+i; 
                    index = i;
                }
            }
            else {    //i的起点在上次找到的点的可达范围之外
                if(i > maxi) {  // 如果在所有那些与上次找到的点相连的点的可达范围之外，表示区间中断，不可达。
                    return false;
                }
                pre = index;  //否则index是新的一跳最远点,因为i脱离了
                index = maxi = -1;
                --i;  //这一步容易忘记， 因为这一个i只是判断了它与之前哪个点脱离了，下一次还得判断它。
            }
        }     

        return true;
    }
};


更新一下，基于上述思路，最优代码应该是这个：只要算出i之前可以跳到的最大index，即可。

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int canArrive = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > canArrive) return false;
            canArrive = max(canArrive, i+nums[i]);
        }
        return true;
    }
};