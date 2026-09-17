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
    int find(int value, vector<int>& inorder) {
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            if (inorder[i] == value) return i;
        }

        return -1;
    }

    int idx = -1;

    TreeNode* tree(vector<int>& preorder, vector<int>& inorder,int st,int end) {

        if(st>end) return NULL;
        idx++;

        TreeNode* root = new TreeNode(preorder[idx]);

        int inIdx = find(preorder[idx], inorder);

        root->left = tree(preorder, inorder, st, inIdx-1);
        root->right = tree(preorder, inorder,inIdx+1,end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();

        return tree(preorder, inorder, 0, n-1);
    }
};
