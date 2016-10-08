//Validate if a given string is numeric.
//
//Some examples:
//"0" => true
//" 0.1 " => true
//"abc" => false
//"1 a" => false
//"2e10" => true
//Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
//
//Update (2015-02-10):
//The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
//

据大神说可以直接使用stetod, 它接受一个char const *s, 然后返回s第一个无法转换的位置（指针）。所以只要用这个函数，比较一下它的第一个无法转换的位置是不是空格，并且它不能只为空格。

class Solution {
    bool isNumber (char const* s) {
        char* endptr;
        
        strtod (s, &endptr);
        
        if (endptr == s) return false;
        
        for (; *endptr; ++endptr)
            if (!isspace (*endptr)) return false;
        
        return true;
    }
public:
    bool isNumber(string s) {
        return isNumber(s.c_str());
    }
};