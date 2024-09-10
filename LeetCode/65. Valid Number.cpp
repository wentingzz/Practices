class Solution {
public:
    int n;
    bool integer(string& s, int& idx){
        if(idx < n and (s[idx] == '-' or s[idx] == '+')) idx++;
        if(idx >= n or s[idx] < '0' or s[idx] > '9') return false;
        while(idx < n and s[idx] >= '0' and s[idx] <= '9') idx++;
        return true;
    }
    bool decimal(string& s, int& idx){
        bool decAround = false;
        if(idx > 0)  decAround = (s[idx-1] >= '0' and s[idx-1] <= '9');
        idx++;
        if(idx >= n or s[idx] < '0' or s[idx] > '9') return decAround;
        while(idx < n and s[idx] >= '0' and s[idx] <= '9') idx++;
        return true;
    }

    bool expo(string& s, int& idx){
        idx++;
        // cout << "expo " << s[idx] << endl;
        // if(idx >= n or s[idx] < '0' or s[idx] > '9') return false;
        return integer(s, idx);
    }
    bool isNumber(string s) {
        int idx = 0;
        n = s.size();
        bool res = integer(s, idx);
        if(s[idx] == '.') res = decimal(s, idx);
        
        if(!res) return false;
        else if(s[idx] == 'e' or s[idx] == 'E') res = expo(s, idx);
        
        if(res and idx >= n) return true;
        return false;
    }
};
