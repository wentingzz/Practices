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
class QuickerSolution {
public:
    vector<int> sums;
    TreeNode* replaceValueInTree(TreeNode* root) {
        levelSum(root, 0);
        replace(root, 0, 0);
        return root;
    }

    void levelSum(TreeNode* node, int lvl){
        if(!node) return;
        if(lvl == sums.size()) sums.push_back(node->val);
        else sums[lvl] += node->val;
        levelSum(node->left, lvl+1);
        levelSum(node->right, lvl+1);
    }

    void replace(TreeNode* node, int sibling, int lvl){
        if(!node) return;
        node->val = sums[lvl] - node->val - sibling;
        int l = (node->left ? node->left-> val : 0);
        int r = (node->right ? node->right-> val : 0);
        replace(node->left, r, lvl+1);
        replace(node->right, l, lvl+1);
    }
};

class Solution {
public:
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long long sum = 0;
        while(!q.empty()){
            int cnt = q.size();
            long long nextSum = 0;
            //pop all nodes on the same level
            for(int i = 0; i < cnt; i++){
                auto [child, cnt] = q.front(); q.pop();
                child->val = sum - cnt;

                int sameParentSum = (child->left ? child->left->val : 0) + (child->right ? child->right->val : 0);
                if(child->left) q.push({child->left, sameParentSum});
                if(child->right) q.push({child->right, sameParentSum});
                nextSum += sameParentSum;
            }
            sum = nextSum;
        }
        return root;
    }
    
};
