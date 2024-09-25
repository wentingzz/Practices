struct Node{
    int count;
    Node* nodes[26];
    Node(){
        count = 0;
        memset(nodes, 0, sizeof(nodes));
    }
    void addStr(string& s, int idx){
        if(idx >= s.size()) return;
        int i = s[idx] - 'a';
        if(!nodes[i]) nodes[i] = new Node();
        nodes[i]->count++;
        nodes[i]->addStr(s, idx+1);
    }

    int getCount(string& s, int idx){
        if(idx >= s.size()) return 0;
        int i = s[idx] - 'a';
        return nodes[i]->count + nodes[i]->getCount(s, idx+1);
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Node* cur = new Node();
        for(string& w: words)cur->addStr(w, 0);

        vector<int> res;
        for(string& w: words)res.push_back(cur->getCount(w, 0));
        return res;
    }
};
