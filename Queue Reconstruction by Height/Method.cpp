//Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
//
//Note:
//The number of people is less than 1,100.
//
//Example
//
//Input:
//[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
//Output:
//[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


//这题贪心法，每一次选取身高最矮的人，从头开始数个数，如果这个位置没有排过，就预留给比它大的，++计数，直到找到一个空位并且计数等于前面比他高的人数。

class Solution {
public:
    static bool comp(const pair<int, int> &a, const pair<int, int> &b) {
        
        if(a.first<b.first) return true;
        
        if(a.first > b.first) return false;
        
        return a.second<b.second;
        
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        
        sort(people.begin(),people.end(),comp);
        
        vector<pair<int, int>> vec(people.size(), make_pair(-1,-1));
        
        for(int i = 0; i < people.size(); ++i) {
            
            int k = 0;
            
            for(int j = 0; j < vec.size(); ++j) {
                
                if(k == people[i].second && vec[j].second == -1) vec[j] = people[i];
                if(vec[j].second == -1 || vec[j].first >= people[i].first) ++k;
                
            }
        }
        
        return vec;
        
    }
};


我们按照身高从矮到高，一样身高k大的排前面 排序。首先从最矮的开始，看他的k，由于后面其他人的升高都大于等于他，那他肯定就在下标k（下标0开始），下一个人依然是剩下那些人最矮的，所以它的位置只要从头数起，没排人的肯定都大于等于他，--k,排了人的肯定比他矮，k不变，找到位置依次放就好了。

class Solution {
public:
    static bool comp(const pair<int, int> &a, const pair<int, int> &b) {
        
        if(a.first != b.first) return  a.first < b.first;
        
        return a.second > b.second;
        
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        
        sort(people.begin(),people.end(),comp);
        
        vector<pair<int, int>> vec(people.size(), make_pair(-1,-1));
        
        for(int i = 0; i < people.size(); ++i) {
            
            int k = 0;
            
            for(int j = 0; j < vec.size(); ++j) {
                
                if(k == people[i].second && vec[j].second == -1) {
                    vec[j] = people[i];
                    break;
                }
                if(vec[j].second == -1) ++k;
                
            }
        }
        
        return vec;
        
    }
};