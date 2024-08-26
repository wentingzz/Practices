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
class BetterSolution {
public:
    int res = 0;
    int target;
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        unordered_map<long long, int> preSum;
        preSum[0] = 1;

        dfs(root, 0, preSum);
        return res;
    }

    void dfs(TreeNode* root, long long sum, unordered_map<long long, int>& preSum){
        if(!root) return;

        long long cur = sum + root->val;
        if(preSum.find(cur - target) != preSum.end()) res += preSum[cur - target];

        preSum[cur]++;
        dfs(root->left, cur, preSum);
        dfs(root->right, cur, preSum);
        preSum[cur]--;
    }
};

class Solution {
public:
    int res = 0;
    int target;
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        vector<long long> preSum = {0};

        dfs(root, preSum);
        return res;
    }

    void dfs(TreeNode* root, vector<long long>& preSum){
        if(!root) return;

        long long cur = preSum.back() + root->val;
        for(long long& p: preSum){
            if(cur - p == target) res++;
        }

        preSum.push_back(cur);
        dfs(root->left, preSum);
        dfs(root->right, preSum);
        preSum.pop_back();
    }
};
