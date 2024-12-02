class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i = 0, j = 1, n = sentence.size();
        while(i < n){
            
            if(sentence[i] == ' '){
                i++, j++;
            }else{
                bool prefix = true;
                for(char& c: searchWord){
                    if(i >= n or c != sentence[i]){
                        prefix = false;
                        while(i < n and sentence[i] != ' ') i++;
                        break;
                    }
                    i++;
                }
                if(prefix) return j;
            }
        }
        return -1;
    }
};
