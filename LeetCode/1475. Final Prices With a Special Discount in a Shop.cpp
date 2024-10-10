class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(prices);
        stack<int> s;
        for(int i = n-1; i > -1; i--){
            while(!s.empty() and s.top() > prices[i]) s.pop();
            if(!s.empty()) res[i] -= s.top();
            
            s.push(prices[i]);

        }
        return res;
    }
};
