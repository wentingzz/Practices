class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        //maximize sum of pass ratios
        priority_queue<tuple<double, int, int>> pq;
        for(auto& c: classes){
            double ratio = 1.0*c[0]/c[1];
            pq.push({1.0*(c[0] + 1)/(c[1] + 1) - ratio, c[0] + 1, c[1] + 1});
        }
        for(int i = 0; i < extraStudents; i++){
            auto [ratio, pass, total] = pq.top(); pq.pop();
            double diff = 1.0*(pass+1)/(total+1) - 1.0*pass/total;
            pq.push({diff, pass+1, total+1});
        }
        double sum = 0;
        while(!pq.empty()){
            auto [ratio, pass, total] = pq.top(); pq.pop();
            sum += 1.0 * (pass-1)/(total-1);
        }
        return sum/classes.size();
    }
};
