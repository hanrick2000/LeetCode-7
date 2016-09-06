//Given an integer, write a function to determine if it is a power of two.
//
//傻逼题
//class Solution {
//public:
//    bool isPowerOfTwo(int n) {
//        
//        int mask = 1;
//        
//        for(int i = 0; i < 31; ++i) {
//            if(n == mask) return true;
//            mask<<=1;
//            
//        }
//        
//        return false;
//        
//    }
//};