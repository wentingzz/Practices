class BestSolution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);

        int moves = 0, ball = 0;
        for(int i = 0; i < n; i++){
            res[i] += moves;
            ball += (boxes[i] == '1');
            moves += ball;
        }

        moves = 0, ball = 0;
        for(int i = n-1; i > -1; i--){
            res[i] += moves;
            ball += (boxes[i] == '1');
            moves += ball;
        }
        return res;
    }
};

class MoreSpaceSolution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int ball = 0;
        vector<long long> prefix(n+1, 0);
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + ball;
            ball += (boxes[i] == '1');
        }
        vector<int> res(n, 0);
        int suffix = 0;
        ball = 0;
        for(int i = n-1; i > -1; i--){
            res[i] = suffix + prefix[i+1];
            ball += (boxes[i] == '1');
            suffix += ball;
        }
        return res;
    }
};
