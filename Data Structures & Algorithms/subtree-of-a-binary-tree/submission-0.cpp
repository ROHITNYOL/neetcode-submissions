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
    bool same(TreeNode* p, TreeNode* q){

        if(p==NULL || q==NULL) return p==q;

        if(p->val!=q->val) return false;

        bool l = same(p->left, q->left);
        bool r = same(p->right, q->right);

        if(!l ||!r) return false;

        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root==NULL || subRoot==NULL) return root==subRoot;

        bool m;
        if(root->val==subRoot->val) m = same(root, subRoot);

        if(m) return true;

        bool l = isSubtree(root->left,subRoot);
        bool r = isSubtree(root->right,subRoot);

        if(l || r) return true;

        return false;

    }

};
