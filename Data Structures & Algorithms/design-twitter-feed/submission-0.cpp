class Twitter {
   public:
    int timestamp = 0;

    unordered_map<int, set<int>> foll;
    unordered_map<int, list<pair<int, int>>> twee;

    Twitter() {}

    void postTweet(int userId, int tweetId) { twee[userId].push_back({timestamp++, tweetId}); }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto &t : twee[userId]) {
            int time = t.first;
            int id = t.second;

            if (pq.size() < 10)
                pq.push({time, id});
            else if (pq.top().first < time) {
                pq.pop();
                pq.push({time, id});
            }
        }

        for (int fl : foll[userId]) {
            for (auto &t : twee[fl]) {
                int time = t.first;
                int id = t.second;

                if (pq.size() < 10)
                    pq.push({time, id});
                else if (pq.top().first < time) {
                    pq.pop();
                    pq.push({time, id});
                }
            }
        }

        vector<int> ans;

        while (pq.size() > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) foll[followerId].insert(followeeId);

    }

    void unfollow(int followerId, int followeeId) {
        if (foll[followerId].count(followeeId)) foll[followerId].erase(followeeId);
    }
};
