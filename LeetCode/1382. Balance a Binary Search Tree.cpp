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
    vector<int> ints;
    int n;
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        n = ints.size();
        return construct(0, n-1);
    }

    TreeNode* construct(int l, int r){
        if(l > r) return nullptr;
        int m = l + (r-l)/2;
        TreeNode* node = new TreeNode(ints[m]);
        node->left = construct(l, m-1);
        node->right = construct(m+1, r);
        return node;
    }

    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        ints.push_back(root->val);
        inOrder(root->right);
    }
};
