class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        for(int i = 0; i < n-1; i++){
            if(sentence[i] == ' ' and sentence[i-1] != sentence[i+1]) return false;
        }
        return sentence[n-1] == sentence[0];
    }
};


class SimilarSolution {
public:
    bool isCircularSentence(string s) {
        if(s[0] != s.back()) return false;
        for(int i = 1; i < s.size()-1; i++){
            if(s[i] == ' ' and s[i-1] != s[i+1]) return false;
        }
        return true;
    }
};
