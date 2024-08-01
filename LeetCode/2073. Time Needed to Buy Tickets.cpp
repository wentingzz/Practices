class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int rounds = tickets[k];
        int res = 0;
        for(int i = 0; i <= k; i++){
            res += min(rounds, tickets[i]);
        }
        for(int i = k+1; i < tickets.size(); i++){
            res += min(rounds-1, tickets[i]);
        }
        return res;
    }
};
