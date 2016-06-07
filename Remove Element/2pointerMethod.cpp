//可以用类似于sortColor那种方法，即2pointer，一头一尾。如果头指针遇到了val,就交换到尾指针那去，尾指针记录了下一个要交换值的位置，从当前尾指针＋1到结尾全是val.所以从头尾指针比如3表示[0,1,2,3]都不会出现val.所以最后返回尾指针＋1. 记住跳出循环的条件是p>q，因为当数组只有一个数时，p=q,然而我们还是得判断一次。

class Solution {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int removeElement(vector<int>& nums, int val) {
    
        int p = 0, q = nums.size()-1;
        
        while(p<=q) {
            if(nums[p] == val) {
                swap(nums[p],nums[q]);
                q--;
            }
            else {
                p++;
                // q--;
            }
        }
        return ++q;
    }
};