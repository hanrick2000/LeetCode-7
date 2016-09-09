//There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
//
//The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
//
//Note:
//All costs are positive integers.
//
//Follow up:
//Could you solve it in O(nk) runtime?

//基本思路和I一模一样，只是在递推时需要costs[i][j] = min(costs[i-1][k](k=0..种类且不等于j)).这里乍一眼看要进行k^2次计算，实际上我们可以线性一遍扫描求出最小值和次小值，因为当j!=最小值下标时，该值就是最小值，当j==最小值下标时，该值就是次小值。


class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>>& costs) {
        // Write your code here
        
        if(!costs.size()) return 0;
        
        int k = costs[0].size();
        
        for(int i = 1; i < costs.size(); ++i) {
            
            int min = INT_MAX, minindex=-1, secondmin = INT_MAX, secondminindex = -1;
            for(int j = 0; j < k; ++j) {
                if(costs[i-1][j] < min) {
                    
                    
                    secondmin = min;
                    secondminindex = minindex;
                    min = costs[i-1][j];
                    minindex = j;
                }
                else if (costs[i-1][j] < secondmin) {
                    
                    secondmin = costs[i-1][j];
                    secondminindex = j;
                    
                }
            }
                
            for(int j = 0; j < k; ++j) {
                
                if(j == minindex) costs[i][j] += secondmin;
                
                else costs[i][j] += min;
                
            }
        
        }
        
        int mini = costs.back()[0];
        
        for(int i = 1; i < k; ++i) {
            mini = min(mini,costs.back()[i]);
        }
        
        return mini;
    }
};