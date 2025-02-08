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
