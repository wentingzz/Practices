class MyCalendarTwo {
public:

    vector<pair<int, int>> one;
    vector<pair<int, int>> doubled;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto& b: doubled){
            if(b.first < end and b.second > start) return false;
        }
        //no tripple book
        for(auto& b: one){
            if(b.first < end and b.second > start){
                //add doubled book time period
                doubled.push_back({max(start, b.first), min(end, b.second)});
            }
        }
        one.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
