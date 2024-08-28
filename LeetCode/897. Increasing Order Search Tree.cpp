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
    vector<TreeNode*> nodes;
    TreeNode* increasingBST(TreeNode* root) {
        addInOrder(root);
        nodes.push_back(nullptr);
        for(int i = 0; i < nodes.size() - 1; i++){
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i+1];
        }
        return nodes[0];
    }

    void addInOrder(TreeNode* node){
        if(!node) return;
        addInOrder(node->left);
        nodes.push_back(node);
        addInOrder(node->right);
    }
};
