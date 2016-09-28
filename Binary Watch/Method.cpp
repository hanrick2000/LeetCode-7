//A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
//
//Each LED represents a zero or one, with the least significant bit on the right.
//
//
//For example, the above binary watch reads "3:25".
//
//Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
//
//Example:
//
//Input: n = 1
//Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//Note:
//The order of output does not matter.
//The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
//The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

//dfs吧  不过实在很容易写错。   把分钟和小时分开。

class Solution {
public:
    void dfsminute(int depth, int minutes, vector<int>& rst, int num, int tre=59, int s = 6) {
        
        if(!num) {
            rst.push_back(minutes);
            return;
        }
        
        for(int i = depth; i < s; ++i) {
            
            minutes += (1<<i);
            if(minutes > tre) break;
            dfsminute(1+i, minutes, rst, num-1, tre, s);
            minutes -= (1<<i);
        }
        
        return;
    }
    

    vector<string> readBinaryWatch(int num) {
        
        vector<string> res;
        
        for(int i = 0; i <= num; ++i) {
            
            vector<int> rst,rst2;
            
            dfsminute(0,0, rst2, num-i,59,6);
            
            dfsminute(0,0, rst, i,11,4);
            
            for(auto x: rst) {
                string hour = to_string(x);
                
                for(auto y: rst2) {
                    
                    string minutes = to_string(y);
                    
                    if(y<10)  minutes = "0" + minutes;
                    
                    res.push_back(hour+":"+minutes);
                }
            }
        }
        
        return res;
    }
};