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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1, leafs2;
        getLeafs(root1, leafs1);
        getLeafs(root2, leafs2);

        if(leafs1.size() != leafs2.size()) return false;
        for(int i = 0; i < leafs1.size(); i++) if(leafs1[i] != leafs2[i]) return false;
        return true;
    }

    void getLeafs(TreeNode* root, vector<int>& res){
        if(!root) return;
        if(root and !root->left and !root->right) return res.push_back(root->val);

        if(root->left) getLeafs(root->left, res);
        if(root->right) getLeafs(root->right, res);
    }

};
