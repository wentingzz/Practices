class VectorMyCalendar {
public:
    vector<pair<int, int>> bs;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(auto& b: bs){
            if(start < b.second and end > b.first) return false;
        }
        bs.push_back({start, end});
        return true;
    }
};

// Node solution
struct Node{
    int start, end;
    Node *left = NULL, *right = NULL;
    Node(int s, int e): start(s), end(e){};
};
class NodeMyCalendar {
public:
    Node* root = NULL;
    MyCalendar() {
    }
    bool book(int start, int end) {
        return book(start, end, root); // Pass the root explicitly
    }

private:
    bool book(int start, int end, Node* &cur) {
        if(!cur){
            cur = new Node(start, end);
            return true;
        }
        if(start >= cur->end) return book(start, end, cur->right);
        if(end <= cur->start) return book(start, end, cur->left);
        return false;
    }
};
