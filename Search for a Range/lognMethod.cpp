//Given a sorted array of integers, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return [-1, -1].
//
//For example,
//Given [5, 7, 7, 8, 8, 10] and target value 8,
//return [3, 4].

//本方法是稍微修改了一下binary search的方法。binary search 通过修改可以得到两个版本：查找到最左边的target的index 和 查找到最右边的target的index。  两种binary search 的时间复杂度都是最坏O(log n).

// 修改要点： p和q永远都是先指向头和尾（包含）。然后while 循环永远都是p<q， 出来后永远都是p==q的情形，只需判断 nums[p] 是不是target就好。如果要找到最左边的，
//i)那么当nums[c] >= target时我们都要向左继续搜索，只是万一nums[c] == target且这正好是最左边的target，我们不能把c点摒弃，所以右指针 变成c (正常二分搜索是变成q = c-1) .
//ii) 当nums[c] < target时 向右搜索。p = c+1;

// 判断循环会不会死  永远检测  p = q-1 时 那一次循环 检测 q = c那个句子。  因为当只有两个数时，c ＝ （p+q）/2永远是向p靠， 所以p = c+1 和 q = c 在本次循环结束后 都会使得p==q. 因此没问题
// findRight 也是相应的做。只不过这一回，q = c-1 , p = c，如果还是按照上一个 c = (p+q)/2。 就会死循环。 我们发现 q = c-1 他肯定会往左靠，但是p = c 他不一定往右靠，想让他往右靠，我们可以让c往右靠， 这样令c = (p+q+1)/2 这就是往右靠。即当p = q-1时 c 会指向右边这个q。这样p == q就能达到我们的目的了。


//同时，还必需注意  上述两种binary search 在跳出循环后肯定是p==q,不会出现p>q的情况。例如findleft..因为我们知道在最后一次进入循环时 p至少也得比q小1 。 即p,q最接近时如下

//p,c  q
// 1   2
//那么无论是q = c 还是 p = c+1 都会使循环跳出。

//但是正常的binary search 会使得p > q。例如
//p,c q
// 1  2
//查找0时会使得q = c - 1。有可能越界 此时我们while出来一定要只能判断[p].

class Solution {
public:

    int findLeft(vector<int>& nums, int target) {
        int p = 0, q = nums.size()-1; 
        while(p<q) {
            int c = (p+q)/2;
            if(nums[c]<target) p = c+1;
            else q = c;  // 可能会死循环的 一定要注意while条件,但根据我们c的定义判断了一下并不会。因为不管p和q是多少，(p+q)/2最终都能导致p == q 或者p == q - 1。
        }
        return nums[p] == target?p:-1;
    }
    
    
    int findRight(vector<int>& nums, int target) {
        int p = 0, q = nums.size()-1; 
        
        while(p<q) {
            int c = (p+q+1)/2;
            if(nums[c]>target) q = c-1;
            else p = c;   //可能死循环，注意c或者while的条件。发现当p == q-1时死循环  我们改一下 c即可. 
        }
        
        return nums[p] == target?p:-1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int a;
        if((a = findLeft(nums,target))==-1) {
            return {-1,-1};
        }
        
        return {a,findRight(nums,target)};
    }
};