//Given two 1d vectors, implement an iterator to return their elements alternately.
//
//For example, given two 1d vectors:
//
//v1 = [1, 2]
//v2 = [3, 4, 5, 6]
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
//
//Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
//
//Clarification for the follow up question - Update (2015-09-18):
//The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:
//
//[1,2,3]
//[4,5,6,7]
//[8,9]
//It should return [1,4,8,2,5,9,3,6,7].


//这题直接按照follow up的标准 实现更一般的解法。用一个整数p记录当前next即将返回的数理应的行数，用一个k维数组记录每一行下次应当访问哪一个下标的数，显然，初始情况全部设0,0。
//每一次调用next，就返回当前坐标的数（肯定没问题，因为调用时会先用hasNext判断当前坐标的有效性，无效会自动跳到下一个有效坐标），结束之后p跳到下一行（可以通过(p+1)%k实现）    每一次hasnext 要对这个理应的行列坐标进行判断是否有效 ，行肯定是有效的，因为p 始终不会达到k，列的话如果大于等于改行的长度就无效了，所以要对剩下的k-1行进行判断是否有有效的坐标出现，即列坐标小于长度，可以通过k-1次+1%k实现。每一次判断hasNext都要改变p。下面程序只要将k改掉就可以完成follow-up.


class ZigzagIterator {
    int p;
    int k;
    vector<int> reg;
    vector<vector<int>> v;
    
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        p = 0;
        k = 2;
        reg.push_back(0);
        reg.push_back(0);
        v.push_back(v1);
        v.push_back(v2);
    }

    int next() {
        int t = v[p][reg[p]];
        ++reg[p];
        p = (p+1)%k;
        
        return t;
    }

    bool hasNext() {
        if(reg[p] >= v[p].size()) {
            for(int i = 1; i < k; ++i) {
                p = (p + i)%k;
                if(reg[p] < v[p].size()) {
                    return true;
                }
            }
            return false;
        }
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
