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
    TreeNode* findCloseParent(TreeNode* root, int s, int d){
        if(!root or root->val == s or root->val == d) return root;
         TreeNode* l = findCloseParent(root->left, s, d);
         TreeNode* r = findCloseParent(root->right, s, d);
         if(l and r) return root;
         if(l) return l;
         return r;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* newRoot = findCloseParent(root, startValue, destValue);
        string s = "", d = "";
        findPath(newRoot, startValue, s);
        findPath(newRoot, destValue, d);
        return string(s.size(), 'U') + d;
    }

    bool findPath(TreeNode* node, int& val, string& res){
        if(!node) return false;
        if(node->val == val) return true;
        res.push_back('L');
        if(findPath(node->left, val, res)){
            return true;
        }
        res.pop_back();
        res.push_back('R');
        if(findPath(node->right, val, res)){
            return true;
        }
        res.pop_back();
        return false;
    }
};
