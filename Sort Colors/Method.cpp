//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note:
//You are not suppose to use the library's sort function for this problem.
//
//click to show follow up.
//
//Follow up:
//A rather straight forward solution is a two-pass algorithm using counting sort.
//First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
//
//Could you come up with an one-pass algorithm using only constant space?


控制两个指针p,q分别代表下一个扫描遇到的0和2应当摆放的下标。控制一个迭代器i，每遇到一个0,放到p(p,i交换元素),i,p++,每遇到一个2，放到q（q,i交换元素）, q--.直到i > q.


class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int p = 0, i = 0, q = nums.size()-1;
        
        while(i <= q)  {
            if(nums[i] == 2) {
                swap(nums[i],nums[q--]);
            }
            
            else if(nums[i]==0) {
                swap(nums[i++], nums[p++]);
            }
            else {
                ++i;
            }
        }
    }
};