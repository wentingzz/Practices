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

class BetterSolution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> vals;

        queue<TreeNode*> q;
        q.push(root);
        bool reverse = false;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                if(reverse) vals.push_back(q.front());
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            if(reverse){
                for(int i = 0, j = vals.size()-1; i < j; i++, j--) swap(vals[i]->val, vals[j]->val);
                vals.clear();
            }
            
            reverse = !reverse;
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> vals;

        queue<TreeNode*> q;
        q.push(root);
        bool reverse = false;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                if(reverse){
                    q.front()->val = vals.back();
                    vals.pop_back();
                }else{
                    if(q.front()->left) vals.push_back(q.front()->left->val);
                    if(q.front()->right) vals.push_back(q.front()->right->val);
                }
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            reverse = !reverse;
        }
        return root;
    }
};
