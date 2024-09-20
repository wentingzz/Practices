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
