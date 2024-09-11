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
