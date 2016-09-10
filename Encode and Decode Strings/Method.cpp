//Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.
//
//Machine 1 (sender) has the function:
//
//string encode(vector<string> strs) {
//  // ... your code
//  return encoded_string;
//}
//Machine 2 (receiver) has the function:
//vector<string> decode(string s) {
//  //... your code
//  return strs;
//}
//So Machine 1 does:
//
//string encoded_string = encode(strs);
//and Machine 2 does:
//
//vector<string> strs2 = decode(encoded_string);
//strs2 in Machine 2 should be the same as strs in Machine 1.
//
//Implement the encode and decode methods.
//
//Note:
//The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
//Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
//Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.

//不能光靠什么','啊'|'啊之类的分隔符去分割这些string，因为string本身也会包含这些分隔符。我们可以每一次记录string的长度，然后用数字和','放置在string最前面然后桥接起来，这样解码时每一次根据一开始的数字确定这个字符串多长，然后就很简单了。

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        
        string res;
        
        for(int i = 0; i < strs.size(); ++i) {
            res += to_string(strs[i].size()) + ',' + strs[i];
        }
        
        return res;
        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        
        vector<string> res;
        
        for(int i = 0; i < s.size(); ++i) {
            
            int tmp = i;
            
            while(s[i] <='9'&&s[i] >='0') {
                ++i;
            }
            
            int len = stoi(s.substr(tmp, i-tmp));
            
            res.push_back(s.substr(i+1,len));
            
            i+=len;
            
        }
        
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));