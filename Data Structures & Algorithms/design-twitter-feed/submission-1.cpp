class Twitter {
private:
    int timestamp = 0;
public:
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<pair<int,int>>> tweets;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        timestamp++;
        tweets[userId].push_back({tweetId, timestamp});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<pair<int,int>, int>> maxHeap;
        // { {timestamp, tweetId} , userId }

        vector<int> users(followees[userId].begin(), followees[userId].end());
        users.push_back(userId);

        for (int user : users) {
            auto& mostRecent = tweets[user];
            if (mostRecent.empty()) continue;
            int timestamp = mostRecent[mostRecent.size()-1].second;
            int tweetId = mostRecent[mostRecent.size()-1].first;

            maxHeap.push({ {timestamp, tweetId}, user  });
        }
        vector<int> res;
        unordered_map<int,int> currentCount;
        if (maxHeap.empty()) return res;
        while (!maxHeap.empty()) {
            if (res.size() == 10) return res;
            int userId = maxHeap.top().second;
            currentCount[userId]++;
            int mostRecentTimestamp = maxHeap.top().first.first;
            int recentTweetId = maxHeap.top().first.second;
            maxHeap.pop();
            res.push_back(recentTweetId);

            int howFarBack = currentCount[userId];
            auto& userTweets = tweets[userId];
            if (int(userTweets.size())-1-howFarBack >= 0) {
                int newTimestamp = userTweets[userTweets.size()-1-howFarBack].second;
                int newTweetId = userTweets[userTweets.size()-1-howFarBack].first;
                maxHeap.push({ {newTimestamp, newTweetId}, userId });
            }
            

        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
