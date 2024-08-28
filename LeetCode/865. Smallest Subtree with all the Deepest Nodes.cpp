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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto res = dfs(root);
        return res.first;
    }

    pair<TreeNode*, int> dfs(TreeNode* node){
        if(!node) return {nullptr, 0};
        auto [ln, ld]= dfs(node->left);
        auto [rn, rd] = dfs(node->right);
        if(ld == rd) return {node, ld+1};
        if(ld > rd) return {ln, ld+1};
        else return {rn, rd+1};
    }
};
