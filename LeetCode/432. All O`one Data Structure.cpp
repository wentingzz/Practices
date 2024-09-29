class Node{
public:
    string val;
    int cnt;
    Node* prev, * next;
    Node(string v, int c): val(v), cnt(c){};
};
class AllOne {
public:
    Node* small = nullptr, * large = nullptr;
    unordered_map<string, Node*> m;
    AllOne() {
        
    }
    
    void inc(string key) {
        if(m.find(key) == m.end()){
            //add a new node
            m[key] = new Node(key, 1);
            addBetween(m[key], nullptr, small);
        }else{
            m[key]->cnt++;
            //move it to right if needed
            Node* cur = m[key]->next;
            remove(m[key]);
            
            while(cur){
                if(cur->cnt >= m[key]->cnt) break;
                cur = cur->next;
            }
            if(cur) addBetween(m[key], cur->prev, cur);
            else addBetween(m[key], large, nullptr);
        }
    }

    void addBetween(Node* node, Node* prev, Node* next){
        if(prev) prev->next = node;
        else small = node; //this should be the smallest node
        node->prev = prev;

        if(next) next->prev = node;
        else large = node;
        node->next = next;
        
    }

    void remove(Node* node){
        if(node->prev) node->prev->next = node->next;
        else small = node->next; //update smalll
        if(node->next) node->next->prev = node->prev;
        else large = node->prev;
    }
    
    void dec(string key) {
        if(m[key]->cnt == 1){
            remove(m[key]);
            m.erase(key);
        }else{
            m[key]->cnt--;
            //move it to right if needed
            Node* cur = m[key]->prev;
            remove(m[key]);
            
            while(cur){
                if(cur->cnt <= m[key]->cnt) break;
                cur = cur->prev;
            }
            if(cur) addBetween(m[key], cur, cur->next);
            else addBetween(m[key], nullptr, small);
        }
    }
    
    string getMaxKey() {
        if(large == nullptr) return "";
        return large->val;
    }
    
    string getMinKey() {
        if(small == nullptr) return "";
        return small->val;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
