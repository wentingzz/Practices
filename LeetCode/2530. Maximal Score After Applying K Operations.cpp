class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int& n: nums) pq.push(n);

        long long res = 0;
        for(int i = 0; i < k; i++){
            res += pq.top();
            pq.push(pq.top() / 3 + (pq.top() % 3 ? 1 : 0));
            pq.pop();
        }
        return res;
    }
};
