

class LRUCache {
public:
    class Node{
        public:
            int val;
            int key;
            Node* prev;
            Node* next;
            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int cap;
    int size = 0;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        Node* cur = m[key];
        deleteNode(cur);
        addNode(cur);
        return cur->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* cur = m[key];
            deleteNode(cur);
            addNode(cur);
            cur->val = value;
        }else{
            Node* cur = new Node(key, value);
            m[key] = cur;

            if(size < cap){
                size++;
            }else{
                m.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            
            addNode(cur);
        }
    }
    
    void addNode(Node* node){
        Node* prev = head;
        Node* next = head->next;
        
        prev->next = node;
        next->prev = node;
        node->prev = prev;
        node->next = next;
    }

    void deleteNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
