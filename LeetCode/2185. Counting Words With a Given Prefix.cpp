class BetterSolution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(string& w: words){
            int n = pref.size();
            if(n > w.size()) continue;
            int i = 0;
            for(; i < n; i++) if(w[i] != pref[i]) break;
            count += (i == n);
        }
        return count;
    }
};

class Solution {
public:
    bool isPrefix(string& word, string& prefix){
        int n = prefix.size();
        if(n > word.size()) return false;
        for(int i = 0; i < n; i++) if(word[i] != prefix[i]) return false;
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(string& w: words) count += isPrefix(w, pref);
        return count;
    }
};
