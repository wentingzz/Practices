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
    int n;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return rec(nums, 0, nums.size()-1);
    }

    TreeNode* rec(vector<int>& nums, int l, int r){
        if(l > r) return nullptr;
        if(l == r) return new TreeNode(nums[l]);
        int idx = l;
        for(int i = l; i <= r; i++){
            if(nums[idx] < nums[i]) idx = i;
        }
        return new TreeNode(nums[idx], rec(nums, l, idx-1), rec(nums, idx+1, r));
    }
};
