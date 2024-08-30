class QuickerSolution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int res = 0, total = neededTime[0], keep = neededTime[0];
        bool same = false;
        for(int i = 1; i < n; i++){
            if(colors[i] == colors[i-1]){
                same = true;
                total += neededTime[i];
                keep = max(neededTime[i], keep);
            }else{
                if(same){
                    same = false;
                    res += total - keep;
                }
                total = keep = neededTime[i];
            }
            // cout << total << " " << keep << endl;
        }
        if(same) res += total - keep;
        return res;
    }
};

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int res = 0;
        for(int i = 1; i < n; i++){
            if(colors[i] == colors[i-1]){
                res += neededTime[i-1];
                int keep = neededTime[i-1];
                while(i < n and colors[i] == colors[i-1]){
                    res += neededTime[i];
                    keep = max(neededTime[i], keep);
                    i++;
                }
                res -= keep;
            }
        }
        return res;
    }
};
