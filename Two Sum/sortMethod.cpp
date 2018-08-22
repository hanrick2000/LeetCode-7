//该方法把nums 变成  pair(value, index), 然后对value 进行排序，就可以保存index。 然后用two pointer 做法 返回相应的index即可  

//  时间  O(nlg(n)) 空间O(n) 

bool compare(const pair<int, unsigned int> &a, const pair<int, unsigned int> &b) {
    return a.first<b.first;
}

class Solution {
public:
    // static bool compare(const pair<int, unsigned int> &a, const pair<int, unsigned int> &b) {
    //     return a.first<b.first;
    // } 

    // 为什么要用static呢？ 因为当std::sort函数调用compare时，没有static就像是
    // 这样: Solution a.compare(c,d)。用到了三个参数，用static 就是这样调用：
    // solution::compare(c,d)两个参数 

    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, unsigned int>> dic(nums.size());
        for(unsigned int i = 0; i < nums.size(); ++i) {
            pair<int, unsigned int> temp = make_pair(nums[i], i);
            dic[i] = temp;
        }
        
        sort(dic.begin(),dic.end(), compare);
        
        int p = 0, q = dic.size()-1;
        
        vector<int> res;

        while(p < q) {  //two pointer 方法
            
            if (dic[p].first + dic[q].first<target) p++;
            else if(dic[p].first + dic[q].first == target) {
                res = {dic[p].second,dic[q].second};
                break;
            }
            else {
                q--;
            }
        }
        
        return res;
        
    }
};

注意  pair默认的排序函数就是按照两个key先后来排的，可以省去cmp函数不写。
class Solution {
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> n(nums.size());
        
        for(int i = 0; i < nums.size(); ++i)  n[i] = {nums[i],i};
        
        sort(n.begin(), n.end());
    
        int p = 0, q = nums.size()-1;
        
        while(p < q) {
            int tmp = n[p].first + n[q].first;
            if(tmp == target) return {n[p].second, n[q].second};
            if(tmp < target) ++p;
            else --q;
        }
        
        return {-1,-1};
    }
};

拓展，如何返回所有解，且无重复？用排序方法无论返回数还是index都没问题，如果要求O(n)得用hashmap，