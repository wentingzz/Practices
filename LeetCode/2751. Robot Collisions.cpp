class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, int>> all; //position, idx
        int n = healths.size();
        for(int i = 0; i < n; i++){
            all.push_back({positions[i], i});
        }
        sort(all.begin(), all.end());


        stack<int> rights;
        for(auto& [pos, idx]: all){
            if(directions[idx] == 'R'){
                rights.push(idx);
            }else{
                while(!rights.empty() and healths[idx] > 0){
                    if(healths[idx] > healths[rights.top()]){
                        healths[idx]--;
                        healths[rights.top()] = 0;
                        rights.pop();
                    }else if(healths[idx] < healths[rights.top()]){
                        healths[idx] = 0;
                        healths[rights.top()]--;
                    }else{
                        healths[idx] = 0, healths[rights.top()] = 0;
                        rights.pop();
                    }
                }
            }
        }

        vector<int> res;
        for(int h: healths) if(h > 0) res.push_back(h);

        return res;
    }
};
