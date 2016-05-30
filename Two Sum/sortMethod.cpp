//该方法把nums 变成  pair(value, index), 然后对value 进行排序，就可以保存index。 然后用two pointer 做法 返回相应的index即可

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

        while(p < q) {
            
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