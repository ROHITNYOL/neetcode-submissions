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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if(root==NULL) return ans;

        queue<TreeNode*> q;

        q.push(root);
        ans.push_back(root->val);
        q.push(NULL);

        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();

            if(node==NULL){

                if(q.empty()) break;

                ans.push_back(q.front()->val);

                q.push(NULL);
                continue;
            } 

            if(node->right) q.push(node->right);
            if(node->left) q.push(node->left);
        }

        return ans;
    }
};
