class TimeMap {
   public:
    unordered_map < string, vector<pair<int, string>> > store;

    TimeMap() {}

    void set(string key, string value, int timestamp) { 
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";

        auto& entries = store[key];

        int st = 0, end = entries.size() - 1;

        string ans = "";
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (entries[mid].first <= timestamp){
                ans = entries[mid].second;
                st = mid+1;

            } else
                end = mid - 1;
        }

        return ans;
    }
};
