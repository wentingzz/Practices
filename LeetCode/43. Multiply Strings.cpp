class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0") return "0";
        int n1 = num1.size(), n2 = num2.size();
        int prod = 0;
        vector<int> res(num1.size() + num2.size());
        for(int i = n1-1; i >= 0; i--){
            for(int j = n2-1; j >= 0; j--){
                prod = (num1[i] - '0') * (num2[j] - '0') + res[i+j+1];
                res[i+j+1] = prod % 10;
                res[i+j] += prod / 10;
            }
        }

        string ret = "";
        int i = 0;
        while(res[i] == 0) i++;
        while(i < n1+n2) ret += to_string(res[i++]);
        return ret;
    }
};
