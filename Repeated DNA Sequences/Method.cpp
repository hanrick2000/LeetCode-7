//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
//Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
//
//For example,
//
//Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
//
//Return:
//["AAAAACCCCC", "CCCCCAAAAA"].


//这题传统的hashmap<stirng>就不说了， 毫无技术可言， 而且慢的一逼。
//关键是怎样用位操作？
//我们可以先对AGCT编码，用两位就可以区分他们，00 01, 10 11,然后10个连续的基因就可以用20bit串来编码，可以用0-- 0x00fffff范围内的一个int来表示; 然后我们就线性扫描整个序列，先把10个基因拿来编程码，这时hash就可以用一个int [0x00100000]数组表示，假设该基因序列出现过，那么这个数组的相对应位被＋＋。 只需要把相对应位为1的放进去即可，否则会重复。后面的10个基因就是上一次的基因去掉第一个基因，末位填上新的基因.可以用移位和&来做。


class Solution {
public:

    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> res;
        
        int len = 0x00100000;
        
        int visited[len] = {0};
        
        int m[128];
        m['A'] = 0;
        m['C'] = 1;
        m['G'] = 2;
        m['T'] = 3;
        
        int tmp = 0;

        for(int i = 0; i < s.size(); ++i) {
            
            tmp <<= 2;
            tmp |= m[s[i]];
            tmp %= len;

            if(i < 9) continue;

            if(++visited[tmp] == 2) {
                res.push_back(s.substr(i-9,10));               
            }
            
        }
           
        return res;
        
    }
};