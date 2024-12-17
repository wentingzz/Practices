class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[26] {};
        for(char& c: s){
            freq[c-'a']++;
        }
        string res = "";
        int toCompleteIdx = -1;
        for(int i = 25; i > -1; i--){
            if(freq[i] == 0) continue;

            if(toCompleteIdx > 0){
                res += 'a' + i;
                freq[i]--;
                i = toCompleteIdx, toCompleteIdx = -1;
            }else{
                if(freq[i] <= repeatLimit){
                    res += string(freq[i], 'a' + i);
                    freq[i] = 0;
                }else{
                    res += string(repeatLimit, 'a' + i);
                    freq[i] -= repeatLimit;
                    toCompleteIdx = i+1;
                }
            }
    
        }

        
        return res;
    }
};
