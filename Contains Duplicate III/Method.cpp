//Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.


//这题核心也是维护一个数据结构，它的大小是k,即线性扫描数组，每一次在该数据结构里面添加当前数。把k以外的从该结构里面删掉。这样所有满足条件的结果都会被我们这个数据结构所覆盖到。然后关键一步我们要能够快速的从该数据结构里的k个数找到其中是否存在与当前nums[i]差距在+-t的数。而使用bst可以在o(lg k)里面找到。具体来说，我们可以用c++的multiset, 这是一个允许元素重复的bst, 它提供upper_bound 和 lower_bound，其中lower_bound 指向大于等于该数的迭代器，upper_bound是大于该元素的迭代器。所以我们来搜索bst中大于等于该点-t的第一个数，如果它存在 而且这个数 是小于nums[i] + t的。那么就返回true

O(nlg(k))

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        multiset<int> BST;
        
        for(int i = 0; i < nums.size(); ++i) {
        
            if(BST.size() > k) {
                BST.erase (BST.find (nums[i-k-1])); 
            }
            
            auto it = BST.lower_bound(nums[i]-t);

            if(it!=BST.end() && *it - nums[i]<= t)  {

                return true;
            }
            
            BST.insert(nums[i]);

        }
        return false;
    }
};