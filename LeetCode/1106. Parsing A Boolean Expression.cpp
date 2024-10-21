class Solution {
public:
    char evaluate(stack<char>& s){
        bool res_or = false, res_and = true;
        while(s.top() == 't' or s.top() == 'f'){
            bool tmp = (s.top() == 't');
            res_or |= tmp;
            res_and &= tmp;
            s.pop();
        }
        char res;
        if(s.top() == '&') res = (res_and ? 't' : 'f');
        else if(s.top() == '|') res = (res_or ? 't' : 'f');
        else res = (res_or ? 'f' :'t');
        s.pop();
        return res;
    }
    bool parseBoolExpr(string exp) {
        stack<char> s;
        for(char& c: exp){
            if(c == ')') s.push(evaluate(s));
            else if(c == '(' or c == ',') continue;
            else s.push(c);
        }
        return s.top() == 't';
    }
};
