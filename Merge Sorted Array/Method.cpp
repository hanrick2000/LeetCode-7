//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
//Note:
//You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
    
这题如果从前开始merge势必会覆盖掉nums1前面的数。我们可以从nums1的后面开始merge，从两个list的尾巴开始，取大的放到nums1的尾部。

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i = m+n-1; i >=0; --i) {
            if(m && n) {
                if(nums1[m-1] < nums2[n-1]) {
                    nums1[i] = nums2[--n];
                }
                else {
                    nums1[i] = nums1[--m];
                }
            }
            else if(m) {
                nums1[i] = nums1[--m];
            }
            else if(n) {
                nums1[i] = nums2[--n];
            }

        }
        
    }
};