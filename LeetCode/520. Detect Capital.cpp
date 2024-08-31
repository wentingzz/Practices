class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0] >= 'a'){
            for(char& c: word){
                if(c < 'a') return false;
            }
        }else{
            int n = word.size();
            if(n > 1 and word[1] < 'a'){ //all capital
                for(int i = 2; i < n; i++){
                    if(word[i] >= 'a') return false;
                }
            }else{
                for(int i = 2; i < n; i++){ //only first letter capital
                    if(word[i] < 'a') return false;
                }
            }
        }
        return true;
    }
};
