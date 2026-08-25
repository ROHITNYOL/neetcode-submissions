#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string ans;
        for (string &s : strs) {
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            // find delimiter '#'
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i)); // length of next string
            string str = s.substr(j + 1, len);
            ans.push_back(str);
            i = j + 1 + len; // move to next encoded string
        }
        return ans;
    }
};
