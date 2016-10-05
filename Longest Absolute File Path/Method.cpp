//Suppose we abstract our file system by a string in the following manner:
//
//The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
//
//dir
//    subdir1
//    subdir2
//        file.ext
//The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
//
//The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
//
//dir
//    subdir1
//        file1.ext
//        subsubdir1
//    subdir2
//        subsubdir2
//            file2.ext
//The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.
//
//We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
//
//Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.
//
//Note:
//The name of a file contains at least a . and an extension.
//The name of a directory or sub-directory will not contain a ..
//Time complexity required: O(n) where n is the size of the input string.
//
//Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.

//这题实际上只要线性扫描一遍，每一次用一个变量记录目录层数，遇到/n表示有新的文件或目录，  再根据遇到的/t的个数来数一数这是第几层文件。用一个tmps string来记录扫描到i时当前的路径是什么，如果下一个文件遇到的层数小于当前层数，随即更改tmp到,从尾部开始删除'\'，直到退到当前的层数位置。为了防止程序错误。可以在tmp之前加一个'\''表示根目录，这样就算退到0层也不用特殊处理。

class Solution {
public:
    int lengthLongestPath(string input) {
    
        string tmp = "/", maxtmp = "/";
        int level = 0;

        for(int i = 0; i < input.size(); ) {
            
            bool file = false;
            while(i < input.size() && input[i]!='\n') {
                if(input[i] == '.')  file = true;
                tmp += input[i++];
            }

            if(file&&tmp.size()>maxtmp.size()) {
                maxtmp = tmp;
            }

            if(i < input.size() && input[i] == '\n') {
                tmp += '/';
                ++i;
            }

            int k = 0;
            while(i < input.size()&&input[i]=='\t') {
                ++k;
                ++i;
            }
            
            if(i >= input.size()) break;

            while (k <= level--)  {
                
                tmp.pop_back();
                while(tmp.back()!='/') tmp.pop_back();
            }
            level = k;
            
        }
        
        return maxtmp.size()-1;
        
    }
};