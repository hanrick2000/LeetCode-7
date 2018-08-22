//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
//
//Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
//
//Note:
//The solution is guaranteed to be unique.


这题凭感觉只要油的总量大于等于耗油总量，肯定找的到一个点，使得顺时针转一圈就可以走到原地。，所以我们只要顺时针，累加净油量，加到一个低谷，那么从下一个点开始，就是净载油量最大时。就是这个点。


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int sum = 0,min_index, mini=INT_MAX;
        
        for(int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];  //从点0到i+1 的总共油累积量
            if(sum<mini) {   //从零开始到i+1该点净剩油最少
                min_index = i;
                mini = sum;
            }
        }
    
        min_index = (min_index+1)%gas.size();
        
        return sum>=0?min_index:-1;
    }
};