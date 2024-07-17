/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class MoreConciseSolution {
public:
    int sumNumbers(TreeNode* root, int currentSum = 0) {
        if (!root) return 0;

        currentSum = currentSum * 10 + root->val;
        if (!root->left && !root->right) return currentSum;

        // Recursively sum for left and right subtrees
        return sumNumbers(root->left, currentSum) + sumNumbers(root->right, currentSum);
    }
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbersHelper(root, 0);
    }

    int sumNumbersHelper(TreeNode* root, int currentSum) {
        if (!root) return 0;

        currentSum = currentSum * 10 + root->val;

        // If we reach a leaf node, return the current sum
        if (!root->left && !root->right) return currentSum;

        // Recursively sum for left and right subtrees
        return sumNumbersHelper(root->left, currentSum) + sumNumbersHelper(root->right, currentSum);
    }
};
