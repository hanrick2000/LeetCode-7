//This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
//
//Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
//
//For example,
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
//    


//很直观，只要初始时记录下每一个单词的位置，连成一个递增数组。随后只要两个有序数组求最接近值即可，可以用二分法。也可 以用merge的sort array的思想稍作修改。

//   用二分法
class WordDistance {
    unordered_map<string,vector<int>> mymap;
public:
    
    WordDistance(vector<string>& words) {
        
        for(int i = 0; i < words.size(); ++i) {
            mymap[words[i]].push_back(i);
        }
    }
    
    int binarySearch(vector<int> &nums, int target) {
        int a = 0, b = nums.size()-1;
        
        while(a<=b) {
            int c = (a+b)>>1;
            
            if(nums[c] == target) return 0;
            
            if(nums[c] < target) a = ++c;
            else b = --c;
        }
        
        if(a&&a<nums.size()) return min(target-nums[a-1],nums[a]-target);
        
        if(!a) return nums[0]-target;
        
        return target - nums.back();
        
    }
    
    int shortest(string word1, string word2) {
        
        if(mymap[word1].size()<mymap[word2].size()) swap(word1,word2);
        
        int mini = INT_MAX;
        for(int i = 0; i < mymap[word2].size(); ++i) {
            mini = min(mini,binarySearch(mymap[word1],mymap[word2][i]));
            
        }
        return mini;
        
        
    }
};

用merge的方法
    int shortest(string word1, string word2) {

        
        int mini = INT_MAX,p = 0, q = 0,lastP = -1, lastQ=-1;
        
        while(p < mymap[word1].size()&&q<mymap[word2].size()) {
            
            mini = min(mini, abs(mymap[word1][p] - mymap[word2][q]));
            
            if(mymap[word1][p] <  mymap[word2][q]) {
                ++p;
            }
            else {
                ++q;
            }
            
        }
        
        return mini;
    }



// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");

