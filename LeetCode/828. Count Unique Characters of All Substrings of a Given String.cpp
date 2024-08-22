class Solution {
public:
    int updateIndex(int (& last)[26][2], int idx, int val){
        if(last[idx][0] == -1) {
            last[idx][0] = val;
            return 0;
        }else if(last[idx][1] == -1){
            last[idx][1] = val;
            return (last[idx][0] + 1) * (val - last[idx][0]);
        }else{
            int res = (last[idx][1] - last[idx][0]) * (val - last[idx][1]);
            last[idx][0] = last[idx][1], last[idx][1] = val;
            return res;
        }
    }
    int uniqueLetterString(string s) {
        int last[26][2], res = 0, n = s.size();
        for(auto l: last)l[0] = l[1] = -1;
        for(int i = 0; i < n; i++)res += updateIndex(last, s[i] - 'A', i);

        for(int i = 0; i < 26; i++){
            if(last[i][1] > -1) res += (last[i][1] - last[i][0]) * (n - last[i][1]);
            else if(last[i][0] > -1) res += (last[i][0] + 1) * (n - last[i][0]);
        }
        return res;
    }
};  
