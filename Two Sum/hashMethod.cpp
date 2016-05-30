//该方法把nums里的值存进hashmap，然后对hashmap里的元素做迭代，如果target - current也在就 返回两个index， 需要注意的是 如果两数一样就得注意原数组出现了几次。

//  时间 average O(n) 空间O(n) 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, vector<unsigned int>> dic;
        
        for(unsigned int i = 0; i < nums.size(); ++i) {
            dic[nums[i]].push_back(i);
        }
        
        vector<int> res;
        
        for(auto &x:dic){
            if(target-x.first==x.first) {
                if(x.second.size()>1) {
                    res = {x.second[0], x.second[1]};
                    break;
                }
            }
            else {
                if(dic.find(target - x.first) != dic.end()) {
                    res = {x.second[0], dic[target-x.first][0]};
                    break;
                }
            }
        }
        
        return res;
    }
};