class Solution {
public:
    string compressedString(string word) {
        string cmp = "";
        int cnt = 1;
        for(int i = 1; i < word.size(); i++){
            if(cnt == 9 or word[i] != word[i-1]){
                cmp += to_string(cnt) + word[i-1];
                cnt = 1;
            }else cnt++;
        }
        return cmp + to_string(cnt) + word.back();
    }
};
