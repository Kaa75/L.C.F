#include <bits/stdc++.h>

using namespace std;

class Twitter {
public:
    vector<pair<int, int>> tweets; // userid, tweetid
    map<int, set<int>> followers;  // followerid, set of following
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back(pair<int,int>(userId, tweetId));
        followers[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> last10;
        
        for (int i = tweets.size() - 1; i >= 0 ; --i)
        {
            if (followers[userId].find(tweets[i].first) != followers[userId].end())
            {
                last10.push_back(tweets[i].second);
                if (last10.size() >= 10)
                    break;
            }
            
        }
        return last10;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followerId);
        if (followeeId == followerId) return;
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].insert(followerId);
        if (followeeId == followerId) return;
        followers[followerId].erase(followeeId);
        
    
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */