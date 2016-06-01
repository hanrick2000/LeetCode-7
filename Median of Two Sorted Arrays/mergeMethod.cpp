//此方法是最简单的merge方法，类似于merge sort里面那样合并两个有序数组，这样只要拿到中间那个数即可。
//时间复杂度O(n)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            
        int p = 0, q = 0, cut_off = (nums1.size()+nums2.size()-1)/2, index = 0, left = 0, right = 0;
        
        bool odd = (nums1.size()+nums2.size())%2, finished = false;
        
        while(p<nums1.size()&&q<nums2.size()) {

            int temp;
            
            if(nums1[p] < nums2[q]) {
                temp = nums1[p];
                p++;
            }
            
            else {
                temp = nums2[q];
                q++;
            }
            
            if(index == cut_off) {
                left = temp;
                if(odd) {
                    finished = true;
                    break;
                }

            }
            
            if(index == cut_off+1) {
                right = temp;
                if(!odd) {
                    finished = true;
                    break;
                }
            }

            index++;
        }
        
        if(finished) {
            
            return odd?left:(left+right)/2.0;
            
        }
        
        while(p<nums1.size()) {
            
            if(index == cut_off) {
                left = nums1[p];
                if(odd) break;
            }
            
            if(index == cut_off+1) {
                right = nums1[p];
                if(!odd) break;
            }

            index++;
            p++;
        }
        
        while(q<nums2.size()) {
            
            if(index == cut_off) {
                left = nums2[q];
                if(odd) break;
            }
            
            if(index == cut_off+1) {
                right = nums2[q];
                if(!odd) break;
            }

            index++;
            q++;
            
        }

        return odd?left:(left+right)/2.0;
        
    }
};