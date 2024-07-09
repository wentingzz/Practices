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
    int distributeCoins(TreeNode* root) {
        pair<int, int> res = dfs(root);
        return res.first;
    }

    pair<int, int> dfs(TreeNode* root){
        if(root == nullptr) return {0, 0};

        pair<int, int> l = {0, 0}, r = {0,0};

        if(root->left) l = dfs(root->left);
        if(root->right) r = dfs(root->right);
        
        int steps = l.first + r.first + abs(l.second) + abs(r.second);
        //left steps + right steps + steps to make all children with 1 coin
        int coins = l.second + r.second + root->val - 1; // total coins to make this subtree all good
        return {steps, coins};
    }
};

class Solution2 {
public:
    int distributeCoins(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, int& res){
        if(root == nullptr) return 0;

        int steps = root->val - 1;
        if(root->left) steps += dfs(root->left, res);
        if(root->right) steps += dfs(root->right, res);
        
        res += abs(steps);
        return steps;
    }
};
