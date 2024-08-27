/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return ",";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return rec(data, idx);
    }

    TreeNode* rec(string data, int& i){
        if(data[i] == ','){
            i++;
            return nullptr;
        }
        int val = 0;
        while(data[i] != ','){
            val = val * 10 + (data[i] - '0');
            i++;
        }
        i++;
        TreeNode* res = new TreeNode(val);
        res->left = rec(data, i);
        res->right = rec(data, i);
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
