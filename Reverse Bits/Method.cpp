//Reverse bits of a given 32 bits unsigned integer.
//
//For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
//
//Follow up:
//If this function is called many times, how would you optimize it?


//从最高位到最低位，一位一位交换，交换时，置0要用&0, 置1要用|1。

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t p = 0x80000000, q=1;
        
        while(p>q) {
            
            bool A = (n&p);//p位
            bool B = (n&q); // q位
            
            
            if(A) {
                n|=q;
            }
            else {
                n&=(~q);
            }
            
            if(B) {
                n|=p;
            }
            else {
                n&=(~p);
            }
            
            p>>=1;
            q<<=1;
            
        }
        return n;
        
    }
};

更简洁一种做法，新建一个数，每一次从原数右边开始，如果是零，新数＊2，如果是1，新数乘以2+1.