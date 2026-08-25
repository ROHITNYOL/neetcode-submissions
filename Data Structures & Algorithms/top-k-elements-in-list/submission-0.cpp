class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;

        int n = nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]]++;

        }

        for(auto it : mp){
            pq.push({it.second,it.first});
        }

        vector<int> ans;

        for(int i=0;i<k;i++){
            int a = pq.top().second;
            pq.pop(); 
            ans.push_back(a);
        }

        return ans;
    }
};
