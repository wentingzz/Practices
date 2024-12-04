class Solution {
public:
    vector<string> digits = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string twoDigit(int num){
        if(num < 20) return digits[num];
        string res = digits[num % 10];
        num /= 10;
        return tens[num] + (res.empty() ? "" : " " + res);
    }

    vector<string> words = {"", "Thousand", "Million", "Billion"};

    string threeDigit(int num){
        if(num == 0) return "";
        string res = twoDigit(num % 100);
        num /= 100;
        if(num){
            res = digits[num % 10] + " Hundred" + (res.empty() ? "" : " " + res);
        }
        return res;
    }

    string numberToWords(int num) {
        if(!num) return "Zero";
        string res = "";
        int idx = 0;
        while(num){
            string three = threeDigit(num % 1000);
            if(!three.empty()) res = three + " " + words[idx] + (res.empty() ? "" : " " + res);
            num /= 1000;
            idx++;
        }
        int n = res.size();
        for(int i = n-1; i >= 0; i--){
            if(res[i] != ' ') return res.substr(0, i+1);
        }
        return res;
    }
};
