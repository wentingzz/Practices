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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        TreeNode* node = delNode(root, to_delete, res);
        if(node) res.push_back(root);
        
        return res;
    }

    // returns true if node is removed
    TreeNode* delNode(TreeNode* node, vector<int>& vals, vector<TreeNode*>& res){
        if(!node) return node;
        if(find(vals.begin(), vals.end(), node->val) != vals.end()){
            node->left = delNode(node->left, vals, res);
            if(node->left) res.push_back(node->left);
            
            node->right = delNode(node->right, vals, res);
            if(node->right) res.push_back(node->right);

            return nullptr;
        }else{
            node->left = delNode(node->left, vals, res);
            node->right = delNode(node->right, vals, res);
            return node;
        }
    }
};
