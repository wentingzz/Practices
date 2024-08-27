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
 
// class Solution {
// public:

//     int getMinimumDifference(TreeNode* root) {
//         int res = INT_MAX;
//         if(root) dfs(root, INT_MIN/2, INT_MAX/2, res);
//         return res;
//     }

//     void dfs(TreeNode* node, int l, int h, int& res){
//         if(!node) return;
//         res = min(res, min(node->val - l, h - node->val));
//         dfs(node->left, l, node->val, res);
//         dfs(node->right, node->val, h, res);
//     }
// };

class Solution {
public:
    vector<int> l;
    int getMinimumDifference(TreeNode* root) {
        if(root) dfs(root);
        int res = l[1] - l[0];
        for(int i = 2; i < l.size(); i++) res = min(res, l[i] - l[i-1]);
        return res;
    }

    void dfs(TreeNode* node){
        if(!node) return;
        dfs(node->left);
        l.push_back(node->val);
        dfs(node->right);
    }
};
