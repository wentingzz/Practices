class Solution {
public:
    string reverseParentheses(string text) {
        int n = text.size();
        stack<int> s;
        for(int i = 0; i < n; i++){
            if(text[i] == '(') s.push(i);
            else if(text[i] == ')'){
                reverse(text.begin() + s.top(), text.begin() + i + 1);
                s.pop();
            }
        }
        string res = "";
        for(char& c: text){
            if(c >= 'a' and c <= 'z') res += c;
        }

        return res;
        
        return res;
    }
};
