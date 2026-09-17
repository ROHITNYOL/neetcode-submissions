/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    void ser(TreeNode* root, string& ans) {
        if (root == NULL) {
            ans += "n,";
            return;
        }
        ans += to_string(root->val) + ",";
        ser(root->left, ans);
        ser(root->right, ans);
    }

    string serialize(TreeNode* root) {
        string ans;
        ser(root, ans);
        return ans;
    }

    TreeNode* dese(const string& data, int& idx) {
        if (idx >= (int)data.size()) return NULL;

        int start = idx;
        while (data[idx] != ',') idx++;
        string token = data.substr(start, idx - start);
        idx++; // skip comma

        if (token == "n") return NULL;

        TreeNode* root = new TreeNode(stoi(token));
        root->left = dese(data, idx);
        root->right = dese(data, idx);
        return root;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        int idx = 0;
        return dese(data, idx);
    }
};
