class Solution {
public:
    // long long gcd(long long a, long long b){
    //     if(b == 0) return a;
    //     return gcd(b, a % b);
    // }
    void parse(string& exp, int& idx, pair<int, int>& res){
        int tmp = 0;
        bool neg = (exp[idx++] == '-');
        while(exp[idx] != '/') tmp = tmp * 10 + exp[idx++] - '0';
        idx++;
        res.first = neg ? -tmp : tmp;
        tmp = 0;
        while(exp[idx] >= '0' and exp[idx] <= '9') tmp = tmp * 10 + exp[idx++] - '0';
        res.second = tmp;
    }

    void calculate(pair<int, int>& res, pair<int, int> plus){
        long long num = 0, den = 0;
        den = res.second * plus.second;
        num = res.first * plus.second + plus.first * res.second;
        int divide;
        if(num < den) divide = abs(gcd(den, num));
        else divide = abs(gcd(num, den));
        den = den / divide, num = num / divide;
        res = {num, den};
    }

    string fractionAddition(string expression) {
        if(expression[0] != '-') expression = "+" + expression;
        pair<int, int> a, b;
        int i = 0, n = expression.size();
        parse(expression, i, a);

        while(i < n){
            parse(expression, i, b);
            calculate(a, b);
        }

        return to_string(a.first) + "/" + to_string(a.second);
    }
};
