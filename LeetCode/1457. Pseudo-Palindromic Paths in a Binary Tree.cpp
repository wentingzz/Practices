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
    int res = 0;
    int count[10];
    int pseudoPalindromicPaths (TreeNode* root) {
        for(int i = 0; i < 10; i++) count[i] = 0;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root){
        if(!root) return;

        count[root->val]++;
        if(!root->left and !root->right) res += isPalindromic();
        dfs(root->left);
        dfs(root->right);
        count[root->val]--;
    }

    bool isPalindromic(){
        int evenFreq = 0;
        for(int i = 0; i < 10 && evenFreq <= 1; i++){
            evenFreq += count[i] % 2;
        }
        return evenFreq <= 1;
    }
};
