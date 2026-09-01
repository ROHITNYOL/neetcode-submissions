class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();

        unordered_set<char> set;

        int left = 0;
        int right = 0;

        int mx = 0;

        while(right<n){

            if(set.contains(s[right])){
                set.erase(s[left]);
                left++;
            }
            else{
                set.insert(s[right]);
                mx = max(mx,right-left+1);
                right++;
            }
        }

        return mx;
    }
};
