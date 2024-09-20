class BetterSolution {
public:
    unordered_map<string, vector<int>> dp;
    vector<int> diffWaysToCompute(string expression) {
        if(!dp[expression].empty()) return dp[expression];
        int n = expression.size();

        vector<int> res;
        for(int i = 0; i < n; i++){
            char c = expression[i];
            if(c == '+' or c == '-' or c == '*'){
                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for(int& l: left){
                    for(int& r: right){
                        if(c == '+') res.push_back(l + r);
                        if(c == '-') res.push_back(l - r);
                        if(c == '*') res.push_back(l * r);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(expression));
        return dp[expression] = res;
    }
};

class Solution {
public:
    void evalExp(vector<int>& ls, vector<int>& rs, char& op, vector<int>& res){
        for(int& l: ls){
            for(int& r: rs){
                if(op == '+') res.push_back(l+r);
                else if(op == '-') res.push_back(l-r);
                else res.push_back(l*r);
            }
        }
    }
    vector<int> diffWaysToCompute(string exp) {
        int n = exp.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(exp[i] < '0' or exp[i] > '9'){
                vector<int> l = diffWaysToCompute(exp.substr(0, i));
                vector<int> r = diffWaysToCompute(exp.substr(i+1));
                evalExp(l, r, exp[i], res);
            }
        }
        if(res.empty()) res.push_back(stoi(exp));
        return res;
    }
};
