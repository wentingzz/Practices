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
    int cnt[3] = {0, 0, 0};
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        count(root, x, 0);
        int sum = cnt[0] + cnt[1] + cnt[2];
        for(int i = 0; i < 3; i++){
            if(sum - cnt[i] < cnt[i]) return true;
        }
        return false;
    }

    void count(TreeNode* root, int x, int idx){
        if(!root) return;
        if(idx == 0 and root->val == x){
            count(root->left, x, 1);
            count(root->right, x, 2);
        }else{
            cnt[idx]++;
            count(root->left, x, idx);
            count(root->right, x, idx);
        }
    }
};
