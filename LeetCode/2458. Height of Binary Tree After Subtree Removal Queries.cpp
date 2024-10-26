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
    unordered_map<int, int> remove2height;
    int maxH = 0;
    void preHeight(TreeNode* node, int cur, int order){
        if(!node) return;
        remove2height[node->val] = max(maxH, remove2height[node->val]);
        maxH = max(maxH, cur);
        if(order == 1){
            preHeight(node->left, cur+1, order);
            preHeight(node->right, cur+1, order);
        }else{
            preHeight(node->right, cur+1, order);
            preHeight(node->left, cur+1, order);
        }
        
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        preHeight(root, 0, 1);
        maxH = 0;
        preHeight(root, 0, -1);
        vector<int> res;
        for(int& q: queries) res.push_back(remove2height[q]);
        return res;
    }
};
