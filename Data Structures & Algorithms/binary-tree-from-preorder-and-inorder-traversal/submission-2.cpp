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

class Solution {
   public:
    unordered_map<int, int> mp;

    TreeNode* tree(vector<int>& preorder, int& preIdx, int st, int end) {
        if (st > end) return NULL;

        TreeNode* root = new TreeNode(preorder[preIdx]);

        int inIdx = mp[preorder[preIdx++]];

        root->left = tree(preorder, preIdx, st, inIdx - 1);
        root->right = tree(preorder, preIdx, inIdx + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        int preIdx = 0;  //declare variable
        return tree(preorder, preIdx, 0, n - 1);
    }
};
