//The API: int read4(char *buf) reads 4 characters at a time from a file.
//
//The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
//
//By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
//
//Note:
//The read function may be called multiple times.

//这题read4 会自动移动被读缓冲的指针，即记录上次调用读到哪。所以本题希望连续调用时“abcdefgh"" 读两次 会有 abcd efgh 而不是abcd abcd。  所以需要一个buffer来记录read4读进来的字符串。用一个pointer记录上次用到了哪里，例如读13个字符，还需要将额外的3个字符在下次输出去。


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    string buffer;
    int point;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
     
    Solution() {
        point = 0;
    }
    int read(char *buf, int n) {
        
        int sum = 0;
        
        while(point<buffer.size()) {
            *buf = buffer[point++];
            ++buf;
            ++sum;
            if(sum == n) return n;
        }
        
        int num = read4(buf);
        for(int i = 0; i < num; ++i) {
            buffer+=*(buf);
            ++buf;
            ++point;
        }
    
        while(num) {
            sum += num;
            if(sum >= n) {
                point-=(sum-n);
                return n;  //读了n了
            }
            num = read4(buf);
            
            for(int i = 0; i < num; ++i) {
                buffer+=*(buf);
                ++buf;
                ++point;
            }
        }
        
        return sum;  //文件读完了还小于n
    }
};