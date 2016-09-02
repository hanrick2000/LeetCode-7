//Given a list of non negative integers, arrange them such that they form the largest number.
//
//For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//
//Note: The result may be very large, so you need to return a string instead of an integer.
    

//这题思路很简单，就是要排序，排序的定义要使得 如果 a+b > b+a  那么 a > b. 这样逆序排序，然后拼起来即可
    
bool compare(string a,string b) {
    return a + b > b + a;
}

class Solution {
public:

    string largestNumber(vector<int>& nums) {
        
        vector<string> st;
        
        for(auto x: nums) {
            st.push_back(to_string(x));
        }
        
        sort(st.begin(),st.end(),compare);
        
        string res;
        
        for(int i = 0; i < st.size(); ++i) {
            res+=st[i];
        }
        if(res.size() && res[0] == '0')  return "0";
        
        return res;
        
    }
};