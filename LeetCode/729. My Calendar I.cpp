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

