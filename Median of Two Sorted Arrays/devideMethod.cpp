//此方法求两个序列的第k小的数：原理如下：假设数组a和b元素个数都不少于k/2。那么我们判断a[k/2-1]和b[k/2-1]这两个元素：
//i)如果a[k/2-1]>b[k/2-1]表示 b[0]到b[k/2-1]这k/2个数的肯定小于第k小的数。可以剔除，在剩下两个序列里求第k-k/2小的数。
//ii)>也类似
//iii)=表明这个数正好是第k个数

//当一个数组的元素少于k/2时，可以直接判断该数组最后一个数a[length-1] 和 b[start+k-length]的值，只要满足两者相加是k即可。

//递归出口: 
//i) k 不断减小 当k = 1， 返回a[0],b[0] 小的那个数
//ii) 当一个数组为空时，返回另一个数组[k-1]那个数。


class Solution {
public:

    int findkstElements(vector<int>& a, vector<int>& b, int start_a, int end_a, int start_b, int end_b, int k) {  //第k个数  从1算起，start包含，end_a不包含
    
        if(k==1) {
            if(end_b!=start_b) {
                return a[start_a]<b[start_b]?a[start_a]:b[start_b];
            }
            else {
                return a[start_a];
            }
        }
        
        if(end_b == start_b) {
            
            return a[start_a+k-1];
        }
    
        if(end_b-start_b >=k/2) {
            
            if(a[start_a+k-k/2-1] == b[start_b+k/2-1]) return b[start_b+k/2-1];
            
            if(a[start_a+k-k/2-1] > b[start_b+k/2-1]) {  //剔除b[start] 到b[start+k/2-1] 共k/2个数， 剩下要找第k-k/2大的数
                
                if(end_a-start_a>end_b-start_b-k/2) {
                    return findkstElements(a, b, start_a, end_a, start_b+k/2, end_b, k-k/2);
                }
                
                else {
                    return findkstElements(b, a, start_b+k/2, end_b, start_a, end_a, k-k/2);
                }
            }
            
            if(a[start_a+k-k/2-1] < b[start_b+k/2-1]) {  //剔除a[start] 到a[start_a+k-k/2-1] 共k-k/2个数， 剩下要找第k/2大的数
                
                if(end_a-start_a-k+k/2>end_b-start_b) {
                    return findkstElements(a, b, start_a+k-k/2, end_a, start_b, end_b, k/2);
                }
                
                else {
                    return findkstElements(b, a, start_b, end_b, start_a+k-k/2, end_a, k/2);
                }
            }
        }
    
        else {
            if(b[end_b-1] == a[start_a+ k-end_b+start_b-1]) {
                return b[end_b-1];
            }
            
            if(b[end_b-1] > a[start_a+ k-end_b+start_b-1]) { //剔除a[start] 到a[start_a+ k-end_b+start_b-1] 共k-end_b+start_b个数， 剩下要找第end_b-start_b大的数
                
                if(end_a-start_a > k) {  //相当于end_a-start_a > k
                    return findkstElements(a, b, start_a+ k-end_b+start_b, end_a, start_b, end_b, end_b-start_b);
                }
                
                else {
                    return findkstElements(b, a, start_b, end_b, start_a+ k-end_b+start_b, end_a, end_b-start_b);
                }
            }
            if(b[end_b-1] < a[start_a+ k-end_b+start_b-1]) { //剔除b[start] 到b[end_b-1] 共end_b-start_b个数， 剩下要找第k-end_b+start_b大的数
            
                return findkstElements(a, b, start_a, end_a, end_b, end_b, k-end_b+start_b);
            }
        }
    
        return 0;
        
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.empty()&&nums2.empty()) return 0;
        
        int len = nums1.size() + nums2.size();
        
        int big,small;
        
        if(nums1.size()>nums2.size()) {
            big = nums1.size();
            small = nums2.size();
            
        }
        
        else {
            big = nums2.size();
            small = nums1.size();
            nums1.swap(nums2);
        }
        
        if(len%2) {
            return findkstElements(nums1,nums2,0,big,0,small, (len+1)/2);
        }
        
        else {
            return (findkstElements(nums1,nums2,0,big,0,small, len/2) + findkstElements(nums1,nums2,0,big,0,small, len/2+1))/2.0;
        }
        
    }
};