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
