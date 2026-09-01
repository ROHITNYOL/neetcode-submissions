class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n1 = s1.size();
        int n2 = s2.size();

        if (n1 > n2) return false;

        vector<int> freq1(26,0),freq2(26,0);

        for(char c : s1) freq1[c-'a']++;

        for(int i=0;i<n1;i++) freq2[s2[i]-'a']++;

        if(freq1==freq2) return true;

        int left = 0;
        for(int i=n1;i<n2;i++){

            freq2[s2[i]-'a']++;
            freq2[s2[left]-'a']--;
            left++;

            if(freq1==freq2) return true;
        }

        return false;

    }
};
