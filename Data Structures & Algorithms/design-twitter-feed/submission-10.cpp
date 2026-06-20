class Twitter {
public:
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<vector<int>>> tweetMap;
    int count;
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minHeap(compare);

        followMap[userId].insert(userId);

        for(int followeeId: followMap[userId])
        {
            if(tweetMap.count(followeeId))
            {
                const vector<vector<int>>& tweets = tweetMap[followeeId];
                int index = tweets.size() - 1;
                minHeap.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }

        while(!minHeap.empty() && res.size() < 10)
        {
            vector<int> tweet = minHeap.top();
            minHeap.pop();
            int index = tweet[3];
            res.push_back(tweet[1]);
            if(index > 0)
            {
                const vector<int>& next = tweetMap[tweet[2]][index - 1];
                minHeap.push({next[0], next[1], tweet[2], index - 1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
