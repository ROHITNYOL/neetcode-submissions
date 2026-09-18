class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;

        for (auto &point : points) {
            int x = point[0];
            int y = point[1];

            int distance = x*x + y*y;

            if (pq.size() < k) {
                pq.push({distance, {x, y}});
            } else {
                if (distance < pq.top().first) {
                    pq.pop();
                    pq.push({distance, {x, y}});
                }
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto [dist, p] = pq.top();
            ans.push_back({p.first, p.second});
            pq.pop();
        }

        return ans;
    }
};
