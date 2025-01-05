class TimeSolution {
public:
    void shiftAt(string& s, int idx, int& shift){
        if(shift == 0) return;
        if(shift > 0){
            if(s[idx] + shift > 'z') s[idx] = s[idx] + shift - 'z' - 1 + 'a';
            else s[idx] += shift;
        }else{
            if(s[idx] + shift < 'a') s[idx] = s[idx] + shift - 'a' + 1 + 'z';
            else s[idx] += shift;
        }
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int shift = 0, n = s.size();
        vector<int> plus(n+1, 0);
        for(vector<int>& shift: shifts){
            int offset = (shift[2] == 0 ? -1 : 1);
            plus[shift[0]] += offset;
            plus[shift[1]+1] += -offset;
        }

        for(int i = 0; i < n; i++){
            shift = (shift + plus[i]+ 26) % 26;
            shiftAt(s, i, shift);
        }
        return s;
        
    }
};
