class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        string res = "";
        for(char& c: s){
            if(c == '(') count++;
            else if(c == ')'){
                if(count == 0) continue;
                count--;
            }
            res += c;
        }
        int j = res.size()-1;
        for(int i = 0; i < count; i++){
            while(j >= 0 and res[j] != '(') j--;
            res.erase(j, 1);
        }
        return res;
    }
};
