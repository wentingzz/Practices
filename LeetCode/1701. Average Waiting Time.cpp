class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long double total = 0;
        int time = 0;
        for(vector<int>& c: customers){
            total += max(time - c[0], 0) + c[1];
            time = max(c[0], time) + c[1];
        }
        return total / customers.size();
    }
};
