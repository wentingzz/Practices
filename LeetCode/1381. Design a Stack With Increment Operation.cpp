class CustomStack {
public:
    vector<int> stack;
    int cap;
    CustomStack(int maxSize) {
        cap = maxSize;
    }
    
    void push(int x) {
        if(cap < 1) return;
        stack.push_back(x);
        cap--;
    }
    
    int pop() {
        if(stack.empty()) return -1;
        int val = stack.back();
        stack.pop_back();
        cap++;
        return val;
    }
    
    void increment(int k, int val) {
        int n = stack.size();
        for(int i = 0; i < k && i < n; i++){
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
