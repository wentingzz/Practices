class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] {};
        for(char& c: word) freq[c-'a']++;
        //I want the most freq letter to require fewest push
        priority_queue<int> pq;
        for(int i = 0; i < 26; i++) if(freq[i] > 0) pq.push(freq[i]);
        vector<int> pushes(4, 2);
        int push = 0, res = 0;
        while(!pq.empty()){
            if(pushes[push] == 10)  push++;
            
            res += pq.top()* (push + 1);
            pq.pop();
            pushes[push]++;
            
        }
        return res;
    }
};
