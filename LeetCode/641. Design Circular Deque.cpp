// Better storage and fair performance (16ms)
class MyCircularDeque {
public:
    vector<int> q;
    int cap = 0;
    MyCircularDeque(int k) {
        cap = k;
    }
    
    bool insertFront(int value) {
        if(cap <= 0) return false;
        q.insert(q.begin(), value);
        cap--;
        return true;
    }
    
    bool insertLast(int value) {
        if(cap <= 0) return false;
        q.push_back(value);
        cap--;
        return true;
    }
    
    bool deleteFront() {
        if(q.size() == 0) return false;
        q.erase(q.begin());
        cap++;
        return true;
    }
    
    bool deleteLast() {
        if(q.size() == 0) return false;
        q.pop_back();
        cap++;
        return true;
    }
    
    int getFront() {
        if(q.size() == 0) return -1;
        return q[0];
    }
    
    int getRear() {
        if(q.size() == 0) return -1;
        return q.back();
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        return cap == 0;
    }
};


// A slightly better performance (15ms)
class Node{
    int val;
    Node *prev, *next;
    Node(int v): val(v){};
    Node(int v, Node* p, Node* n = nullptr): val(v), prev(p), next(n){};
};
class MyCircularDeque {
public:
    Node* first = nullptr, *last = nullptr;
    int cap = 0;
    MyCircularDeque(int k) {
        cap = k;
    }
    
    bool insertFront(int value) {
        if(cap <= 0) return false;
        if(first == nullptr){
            first = new Node(value), last = first;
        }else{
            Node* tmp = new Node(value, nullptr, first);
            first->prev = tmp, first = tmp;
        }
        cap--;
        return true;
    }
    
    bool insertLast(int value) {
        if(cap <= 0) return false;
        if(first == nullptr){
            first = new Node(value), last = first;
        }else{
            Node* tmp = new Node(value, last);
            last->next = tmp, last = tmp;
        }
        cap--;
        return true;
    }
    
    bool deleteFront() {
        if(first == nullptr) return false;
        if(first == last) first = nullptr, last = nullptr;
        else{
            first = first->next, first->prev = NULL;
        }
        cap++;
        return true;
    }
    
    bool deleteLast() {
        if(last == nullptr) return false;
        if(first == last) first = nullptr, last = nullptr;
        else{
            last = last->prev, last->next = nullptr;
        }
        cap++;
        return true;
    }
    
    int getFront() {
        if(first == nullptr) return -1;
        return first->val;
    }
    
    int getRear() {
        if(last == nullptr) return -1;
        return last->val;
    }
    
    bool isEmpty() {
        return first == nullptr;
    }
    
    bool isFull() {
        return cap == 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
