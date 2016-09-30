//There are N children standing in a line. Each child is assigned a rating value.
//
//You are giving candies to these children subjected to the following requirements:
//
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//What is the minimum candies you must give?


//左边扫一遍，假设第一个人1颗糖。如果i+1个rating大于i，那么糖果数目多一个，否则糖果设为1，然后反向扫一遍，如果当前rating大于i+1且糖没有大于i+1的，就让糖变成i+1.

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        if(ratings.empty()) return 0;
        
        vector<int> candy(ratings.size(),0);
        
        candy[0] = 1;
   
        for(int i = 1; i < ratings.size(); ++i) {
            if(ratings[i] > ratings[i-1]) candy[i] = candy[i-1] + 1;
            else candy[i] = 1;
        }
        
        for(int i = ratings.size()-2; i >=0; --i) {
            if((ratings[i] > ratings[i+1]) && (candy[i] <= candy[i+1])) candy[i] = candy[i+1] + 1;
        }
        
        int sum = 0;
        for(int i = 0; i < candy.size(); ++i) sum += candy[i];
        
        return sum;
        
    }
};


