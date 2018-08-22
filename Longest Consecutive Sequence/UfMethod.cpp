用union find只要让每一个数和比它小1的数去union即可，不过我们第一步得通过知道一个数，获得它的下标，所以得hashmap.然后注意去重。重复的数得忽略。
class Uf {
    vector<int> parent;
    vector<int> size;
    int n;
public:
    Uf(int n): parent(n), size(n,1), n(n) {
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findSet(int x) {
        if(x != parent[x]) {
            parent[x] = findSet(parent[x]);
        }
        return parent[x];
    }
    
    void Union(int a, int b) {
        int x = findSet(a), y = findSet(b);
        if(x == y) return;
        
        if(size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
        --n;
        return;
    }
    
    int component() {
        return n;
    }
    int largeSize() {
        int res = 0;
        for(auto x: size) res = max(res, x);
        return res;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mymap;
        int count = 0;
        for(int &num: nums) {
            if(!mymap.count(num)) {
                mymap[num] = count;
                nums[count++] = num;
            }
        }
        
        Uf uf(count);
        
        for(int i = 0; i < count; ++i) {
            if(mymap.count(nums[i]-1)) {
                uf.Union(i,mymap[nums[i]-1]);
            }
        }
        
        return uf.largeSize();
    }
};