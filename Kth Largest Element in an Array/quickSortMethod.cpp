//该方法利用了  快排的一步，找中枢pivot, 然后把所有比pivot大的数放到pivot前，小的数放到pivot后. 这一步需要用O(n).
//完了后  我们就知道pivot现在是第p大的数。要求第k大的数，如果p==k,那么返回该数，p<k, 说明要找的数在数组后面第k-p个，递归调用。否则递归在前面找第k个大的数
//    
//O(n).平均 每一次分一半的话  就是n*1 + n/2 + n/4 +... = 2n;
//最坏，n + n-1 + n-2 + n-3... O(n^2).

class Solution {
public:

    // int quickSortHelper()

    int findKthLargestHelper(vector<int>& nums, int start, int end, int k) {
        if(start == end) return nums[start];
        
        while(start < end) {
            int pivot = nums[start], p = start, q = end;
        
            while(p<q) {
            
                while(nums[q] <= pivot && q > p) {  //等号必不可少，不然可能会遇到[1,1,1,1]这样的例子而死循环。
                    --q;
                }
                
                nums[p] = nums[q];
                
                while(nums[p] >= pivot &&p < q) {
                    ++p;
                }
                
                nums[q] = nums[p];
            }
            
            nums[p] = pivot;
            
            int pos  = p - start + 1;
            
            if(pos == k) return pivot;
            
            if(pos < k) {
                
                start = p+1;
                k-= pos;
            }
            
            else {
                end = p-1;
            }
        }
        
        return nums[start];
    
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        return findKthLargestHelper(nums, 0, nums.size()-1, k);
    }
};