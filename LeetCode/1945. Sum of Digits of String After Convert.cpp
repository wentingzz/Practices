class Solution {
public:
    int addsDigits(int num){
        int res = 0;
        while(num){
            res += (num % 10);
            num /= 10;
        }
        return res;
    }
    int getLucky(string s, int k) {
        char offset = 'a' - 1;
        int sum = 0;
        for(char& c: s) sum += addsDigits(c - offset);
        for(int i = 1; i < k; i++){
            sum = addsDigits(sum);
        }
        return sum;
    }
};
