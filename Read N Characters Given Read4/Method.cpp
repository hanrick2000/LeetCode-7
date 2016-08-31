//The API: int read4(char *buf) reads 4 characters at a time from a file.
//
//The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
//
//By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
//
//Note:
//The read function will only be called once for each test case.

//这题 每调用一次read4,会返回读了x个字符，且会在缓冲区自动输出buf[0:x]. 所以，我们要读n个字符串，可以循环调用read4直到读完整个缓冲buff,每一次调用记得用一个sum变量纪录已经堵读了多少，该读的buf地址为buf+sum.循环中  一遇到sum>=n时 就反回n,这样就算read4读多了，你反回正确的长度，就可以截断。


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int num = read4(buf);
        int sum = 0;

        while(num) {
            sum += num;
            if(sum >= n) return n;  //读了n了
            num = read4(buf+sum);
        }
        
        
        
        return sum;  //文件读完了还小于n
        
    }
};