class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char ch : tasks)
            freq[ch - 'A']++;

        int maxFreq = *max_element(freq.begin(), freq.end());
        int countMax = count(freq.begin(), freq.end(), maxFreq);

        int required = (maxFreq - 1) * (n + 1) + countMax;

        return max(required, (int)tasks.size());
    }
};
