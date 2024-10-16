class Solution {
public:
    void add(string& s, pair<int, char>& c1, pair<int, char>& c2){
        int repeat = (c2.first == c1.first ? 2 : 1);
        if(!s.empty() and s.back() == c1.second){
            s += string(min(repeat, c2.first), c2.second);
            s += string(min(2, c1.first), c1.second);
        }else{
            s += string(min(2, c1.first), c1.second);
            s += string(min(repeat, c2.first), c2.second);
        }

        c1.first = max(c1.first-2, 0);
        c2.first = max(c2.first-repeat, 0);
    }
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        string res = ""; 
        while(pq.size() > 1){
            auto c1 = pq.top(); pq.pop();
            auto c2 = pq.top(); pq.pop();
            add(res, c1, c2);
            if(c1.first > 0) pq.push(c1);
            if(c2.first > 0) pq.push(c2);
        }
        if(!pq.empty() and (res.empty() or res.back() != pq.top().second)){
            res += string(min(2, pq.top().first), pq.top().second);
        }
        return res;
    }
};
