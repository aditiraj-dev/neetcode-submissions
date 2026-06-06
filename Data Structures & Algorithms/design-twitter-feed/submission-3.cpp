class Twitter {
public:
    int time;
    unordered_map<int, unordered_set<int>> follows; //maps user to who they follow
    unordered_map<int, vector<pair<int,int>>> tweets;  //maps user to their tweets
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> feed = tweets[userId]; //now contains the tweets made by user

        for(int followee : follows[userId]) //ever person user follows
        {
            for(auto tweet : tweets[followee]) //add their tweets
                feed.push_back(tweet);
        }

        sort(feed.rbegin(), feed.rend());

        vector<int> res;

        for(int i = 0; i < min(10, (int)feed.size()); i++)
        {
            res.push_back(feed[i].second);
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(follows[followerId].count(followeeId))
        {
            follows[followerId].erase(followeeId);
        }
    }
};
