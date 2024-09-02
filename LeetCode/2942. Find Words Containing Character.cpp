class Solution {
public:

    bool checkChar(string& s, char x){
        for(char& c: s) if(c == x) return true;
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i = 0; i < words.size(); i++) if(checkChar(words[i], x)) res.push_back(i);
        return res;
    }
};
