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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int res = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> idx(size);
            vector<int> nums(size);
            iota(idx.begin(), idx.end(), 0);
            
            for(int i = 0; i < size; i++){
                TreeNode *node = q.front(); q.pop();
                nums[i] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            sort(idx.begin(), idx.end(), [&](int a, int b){
                return nums[a] < nums[b];
            });
            int i = 0, j;
            while(i < size){
                j = idx[i];
                if(i != j){
                    swap(idx[i], idx[j]);
                    res++;
                } else i++;
            }
        }
        return res;
    }
};
