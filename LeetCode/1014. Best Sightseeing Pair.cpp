class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0, score = values[0];

        for(int i = 1; i < values.size(); i++){
            res = max(res, score + values[i] - i);
            score = max(score, values[i] + i);
        }
        return res;
    }
};
