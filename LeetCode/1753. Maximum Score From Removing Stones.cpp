class BestSolution {
public:
    int maximumScore(int a, int b, int c) {
        int largest = max(a, max(b,c));
        int twoSmall = a + b + c - largest;
        if(twoSmall < largest) return twoSmall;

        return (twoSmall + largest) / 2;
    }
};

class MiddleSolution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a); pq.push(b); pq.push(c);
        int res = 0, s1, s2;
        while(pq.size() > 1){
            s1 = pq.top(); pq.pop();
            s2 = pq.top(); pq.pop();
            if(s1 > 1) pq.push(s1 - 1);
            if(s2 > 1) pq.push(s2 - 1);
            res++;
        }
        return res;

    }
};

class SlowSolution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a); pq.push(b); pq.push(c);
        int res = 0, s1, s2;

        while(pq.size() > 1){
            int points;
            s1 = pq.top(); pq.pop();
            s2 = pq.top(); pq.pop();
            cout << s1 << " " << s2 << " " << pq.top() << endl;
            if(!pq.empty() and pq.top() > s1 - s2) points = max(1, s1 - pq.top()); //I want s1 to become s3
            else points = s2;
            res += points;
            if(s1 > points) pq.push(s1 - points);
            if(s2 > points) pq.push(s2 - points);
        }
        return res;

    }
};
