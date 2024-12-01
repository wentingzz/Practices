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
    int limit;
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        limit = distance;
        dfs(root, res);
        return res;
    }

    deque<int> dfs(TreeNode* node, int& count){
        if(!node) return {0};
        if(!node->left and !node->right) return {1};
        deque<int> l = dfs(node->left, count);
        deque<int> r = dfs(node->right, count);
        for(int i = 0; i < min((int)l.size(), limit); i++){
            for(int j = 0; j < r.size() && i + j + 1 < limit; j++){
                count += l[i] * r[j];
            }
        }
        deque<int> res = {0};
        for(int i = 0; i < min(limit, max((int)l.size(), (int)r.size())); i++){
            res.push_back((i < l.size() ? l[i] : 0) + (i < r.size() ? r[i] : 0));
        }
        return res;
    }
};
