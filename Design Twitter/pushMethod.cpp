//Map + Set + PriorityQueue
//
//系统应当维护下列信息：
//
//1). 一个全局的推文计数器：postCount 用户发推文时，计数器+1
//
//2). 推文Id -> 推文计数器的映射：tweetIdMap 用来记录推文的次序
//
//3). 推文Id -> 用户Id的映射：tweetOwnerMap 用来记录推文的发送者是谁
//
//4). 用户Id -> 关注对象集合的映射： followeeMap 用来记录用户的关注对象（关注/取消关注）
//方法的实现：
//
//1). 关注 follow / 取消关注 unfollow：
//
//只需要维护followeeMap中对应的关注对象集合followeeSet即可
//2). 发送推文 postTweet：
//
//更新推文计数器postCount，维护tweetIdMap；
//
//向用户的推文发送列表中新增一条记录
//3). 获取推文推送 getNewsFeed：
//
//这里需要使用优先队列PriorityQueue，记为pq
//
//遍历用户的关注对象列表，将每一位关注对象的最新一条推文添加至pq中。
//
//然后从pq中弹出最近的一条推文，记为topTweetId；
//
//通过tweetOwnerMap找到这条推文的发送者userId，然后将该发送者的下一条比较新的推文添加至pq。
//
//直到弹出10条最新的推文，或者pq为空为止。

struct Tweet {
    int user;
    int id;
    int timestamp;
    int index;
    Tweet(int userId, int tweetId, int ts, int ind): user(userId), id(tweetId), timestamp(ts), index(ind) {}
    Tweet(): user(0), id(0), timestamp(0), index(-1) {}
};
struct cmp {
    
    bool operator() (const Tweet &a, const Tweet &b) {
        return a.timestamp < b.timestamp;
    }
      
};

class Twitter {
    
    unordered_map<int, vector<Tweet>> tweet;
    unordered_map<int,unordered_set<int>> followtable;
    int timestamp;
        
public:
    /** Initialize your data structure here. */
    Twitter(): timestamp(0) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back(Tweet(userId, tweetId, ++timestamp, tweet[userId].size()));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        
        follow(userId, userId);
        vector<int> res;
        
        priority_queue<Tweet, vector<Tweet>, cmp> pq;
        
        int count = 0;
        
        
        for(x: followtable[userId]) {
            if(tweet[x].size()) pq.push(tweet[x].back());
        }
        
        
        while(pq.size() && count++ < 10) {
            
            Tweet tmp = pq.top();
            
            pq.pop();
            
            res.push_back(tmp.id);
            
            if(tmp.index) {
                pq.push(tweet[tmp.user][tmp.index-1]);
            }
        }
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followtable.find(followerId) == followtable.end()) {
            followtable[followerId] = {};
        }
        
        followtable[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followtable.find(followerId) == followtable.end()) {
            followtable[followerId] = {};
            return;
        }
        
        if(followtable[followerId].find(followeeId)==followtable[followerId].end()) return;
        
        followtable[followerId].erase(followtable[followerId].find(followeeId));
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */