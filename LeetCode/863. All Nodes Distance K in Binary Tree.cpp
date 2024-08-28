/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        addChild(target, k);

        addParent(root, target, k); //upward
        return res;
    }

    void addChild(TreeNode* n, int k){
        if(!n) return;
        if(k == 0) res.push_back(n->val);
        else{
            addChild(n->left, k-1);
            addChild(n->right, k-1);
        }
    }

    int addParent(TreeNode*node, TreeNode* target, int k){
        if(!node) return -1;
        if(node->val == target->val) return k-1;
        int l = addParent(node->left, target, k);
        if(l == 0) res.push_back(node->val);
        else if(l > 0){
            addChild(node->right, l-1);
            return l-1;
        }
        int r = addParent(node->right, target, k);
        if(r == 0) res.push_back(node->val);
        else if(r > 0){
            addChild(node->left, r-1);
            return r-1;
        }
        return -1;

    }


};
