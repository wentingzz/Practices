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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);

        return res;
    }

    void dfs(TreeNode* node, vector<int>& res, int lvl){
        if(!node) return;
        if(res.size() == lvl) res.push_back(node->val);
        else res[lvl] = max(res[lvl], node->val);

        dfs(node->left, res, lvl+1);
        dfs(node->right, res, lvl+1);
    }
};
