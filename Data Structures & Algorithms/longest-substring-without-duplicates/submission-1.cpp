class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0, right = 0, mx = 0;
        int n = s.size();

        while (right < n) {
            while (set.count(s[right])) {  // keep shrinking until duplicate gone
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            mx = max(mx, right - left + 1);
            right++;
        }
        return mx;
    }
};
