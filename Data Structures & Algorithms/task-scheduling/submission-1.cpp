class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char ch : tasks) freq[ch - 'A']++;

        int maxElement = *max_element(freq.begin(),freq.end());

        int maxCounts = count(freq.begin(),freq.end(),maxElement);

        return max(((maxElement-1)*(n+1) + maxCounts), (int)tasks.size());
    }
};
