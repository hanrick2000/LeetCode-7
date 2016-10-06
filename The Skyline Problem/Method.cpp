//A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).
//
// Buildings Skyline Contour
//The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
//
//For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
//
//The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.
//
//For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
//
//Notes:
//
//The number of buildings in any input list is guaranteed to be in the range [0, 10000].
//The input list is already sorted in ascending order by the left x position Li.
//The output list must be sorted by the x position.
//There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]

//如果按照一个矩形一个矩形来处理将会非常麻烦，我们可以把这些矩形拆成两个点，一个左上顶点，一个右上顶点。将所有顶点按照横坐标排序后，我们开始遍历这些点。遍历时，通过一个堆来得知当前图形的最高位置。堆顶是所有顶点中最高的点，只要这个点没被移出堆，说明这个最高的矩形还没结束。对于左顶点，我们将其加入堆中。对于右顶点，我们找出堆中其相应的左顶点，然后移出这个左顶点，同时也意味这这个矩形的结束。具体代码中，为了在排序后的顶点列表中区分左右顶点，左顶点的值是正数，而右顶点值则存的是负数。
//分别将每个线段的左边节点与右边节点存到新的vector height中，根据x坐标值排序，然后遍历求拐点。求拐点的时候用一个最大化heap来保存当前的楼顶高度，遇到左边节点，就在heap中插入高度信息，遇到右边节点就从heap中删除高度。分别用pre与cur来表示之前的高度与当前的高度，当cur != pre的时候说明出现了拐点。在从heap中删除元素时要注意，我使用priority_queue来实现，priority_queue并不提供删除的操作，所以又用了别外一个unordered_map来标记要删除的元素。在从heap中pop的时候先看有没有被标记过，如果标记过，就一直pop直到空或都找到没被标记过的值。别外在排序的时候要注意，如果两个节点的x坐标相同，我们就要考虑节点的其它属性来排序以避免出现冗余的答案。且体的规则就是如果都是左节点，就按y坐标从大到小排，如果都是右节点，按y坐标从小到大排，一个左节点一个右节点，就让左节点在前。下面是AC的代码。


//思路就是这样，按照横坐标从小到大排序，纵坐标如果是建筑物的左边点则从大到小排序，否则按从小到大排序，即相同横坐标，我们希望高的先被扫描到加进来，后被踢出去。用一个优先队列保存当前视线范围内最高的地平线。每一次拐点的出现都是在某一个建筑物的右边界到来时，才有可能造成，具体说来是当前视线点最高建筑物的右边界到来。

//算法：
//初始化地平线为0.
//从左到右扫描点，进行一下循环
//1）如果扫描到左顶点，把高度放到PQ里 否则是右顶点，把其对应的左顶点删除。
//2）看看现在视线里的最高点（堆顶元素，没有就为0，也可以提前push一个0进去防止过多的判空）与上一次循环有没有变化，有变化就push拐点，更改当前的最高点。


class Solution {
public:

    static bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
        if(a.first!=b.first) return a.first < b.first;
        
        return a.second > b.second;
    }

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int,int>> points;
        vector<pair<int, int>> res;
        
        for(auto x: buildings) {
            points.push_back({x[0],x[2]});
            points.push_back({x[1],-x[2]});
        }
        
        sort(points.begin(), points.end(), cmp);
        
        unordered_map<int,int> visited;
        
        priority_queue<int> pq;
        
        int prev = 0;
        pq.push(0);  //栈空后，依然可以用pq.top()来获取地平线（海拔为0）. 不用额外判空。

        for(auto x: points) {
            if(x.second > 0) {
                
                pq.push(x.second);
                
            } else {
                
                ++visited[-x.second];
                
                while(pq.size()&&visited[pq.top()]>0) {
                    
                    --visited[pq.top()];
                    pq.pop();
                }
            }
            
            int cur = pq.top();
            
            if(cur!=prev) {
                
                prev = cur;
                res.push_back({x.first,cur});
            }
        }
        
        return res;
    }
};