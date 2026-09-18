class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int x = pq.top(); pq.pop(); // heaviest
            int y = pq.top(); pq.pop(); // second heaviest

            if (x != y) {
                pq.push(x - y); // push the difference
            }
            // if x == y, both destroyed → nothing pushed
        }

        return pq.empty() ? 0 : pq.top();
    }
};
