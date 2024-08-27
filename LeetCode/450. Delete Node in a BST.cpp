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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else{
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            int leaf = findPre(root->left);
            root->val = leaf;
            root->left = deleteNode(root->left, leaf);
        }
        return root;
    }

    int findPre(TreeNode* root){
        if(!root->right) return root->val;
        return findPre(root->right);
    }
};
