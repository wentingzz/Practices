struct Node{
public:
    int freq;
    int val;
    int idx;

    Node(int f, int val, int idx): freq(f), val(val), idx(idx){}

    bool operator<(const struct Node& other) const
    {
        //Your priority logic goes here
        if(freq != other.freq){
            return freq < other.freq;
        }
        return idx < other.idx;
    }
};

class FreqStack {
public:
    unordered_map<int, int> m;
    priority_queue<Node> pq;
    int size=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        m[val]++;
        size++;
        pq.push(Node(m[val], val, size));
    }
    
    int pop() {
        int val = pq.top().val;
        pq.pop();
        m[val]--;
        return val;
    }
};


/**
 * Better implementation (quicker)
*/
class FreqStack {
public:
    int maxFreq = 0;
    unordered_map<int, int> valToFreq;
    vector<vector<int>> freqToVal = {{}};
    FreqStack() {
    }
    
    void push(int val) {
        int freq = valToFreq[val]++;
        if(freq > maxFreq){
            maxFreq = freq;
            freqToVal.push_back({});
        }
        freqToVal[freq].push_back(val);
    }
    
    int pop() {
        int res = freqToVal[maxFreq].back();
        valToFreq[res]--;
        freqToVal[maxFreq].pop_back();
        if(freqToVal[maxFreq].size() == 0){
            maxFreq--;
        }
        return res;
    }
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
