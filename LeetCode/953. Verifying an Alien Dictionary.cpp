class Solution {
public:
    bool wrongOrder(string prev, string cur, int orders[]){
        int n = prev.size();
        int m = min(prev.size(), cur.size());
        for(int i = 0; i < m; i++){
            if(prev[i] != cur[i]) return orders[prev[i] - 'a'] > orders[cur[i] - 'a'];
        }
        return n > m; //same prefix
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int orders[26];
        for(int i = 0; i < 26; i++){
            orders[order[i] - 'a'] = i;
        }
        for(int i = 1; i < words.size(); i++){
            if(wrongOrder(words[i-1], words[i], orders)){
                return false;
            }
        }
        return true;
    }
};
