class BestNumberContainers {
public:
    // map<int, int> m;
    unordered_map<int, int> i2n;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> n2i;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        i2n[index] = number;
        n2i[number].push(index);
    }
    
    int find(int number) {
        if(n2i.find(number) == n2i.end()) return -1;
        while(!n2i[number].empty()){
            int idx = n2i[number].top();
            if(i2n[idx] == number) return idx;
            n2i[number].pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

class SlowerNumberContainers {
public:
    // map<int, int> m;
    unordered_map<int, int> i2n;
    unordered_map<int, set<int>> n2i;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(i2n.find(index) != i2n.end()){// replace
            n2i[i2n[index]].erase(index);
        }
        i2n[index] = number;
        n2i[number].insert(index);
    }
    
    int find(int number) {
        if(n2i.find(number) == n2i.end() or n2i[number].size() == 0) return -1;
        return * n2i[number].begin();
    }
};
