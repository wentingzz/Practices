class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int& g: gifts) pq.push(g);
        for(int i = 0; i < k; i++){
            pq.push(sqrt(pq.top()));
            pq.pop();
        }
        long long res = 0;
        while(!pq.empty()){
            res += pq.top(); pq.pop();
        }
        return res;
    }
};
