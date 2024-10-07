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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        rec(root);
        return res;
    }

    int rec(TreeNode* root) {
        if(!root) return 0;
        int l = 0, r = 0;
        if(root->left) l = max(0, rec(root->left));
        if(root->right) r = max(0, rec(root->right));
        res = max(res, l + r + root->val);
        return root->val + max(l, r);
    }
};
