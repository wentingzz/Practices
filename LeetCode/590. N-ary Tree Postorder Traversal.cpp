/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class BetterSolution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res = {};
        rec(root, res);
        return res;
    }
    void rec(Node* root, vector<int>& res){
        if(!root) return;
        for(Node* n: root->children) rec(n, res);
        res.push_back(root->val);
    }
};
