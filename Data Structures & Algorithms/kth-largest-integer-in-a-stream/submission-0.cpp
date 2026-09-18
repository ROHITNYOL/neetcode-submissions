class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int> > pq;
    int limit;

    KthLargest(int k, vector<int>& nums) {
        limit = k;
        for (int num : nums) {
            if (pq.size() < k)
                pq.push(num);
            else {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }
    }

    int add(int val) {
        if (pq.size() < limit)
            pq.push(val);
        else {
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }

        return pq.top();
    }
};
