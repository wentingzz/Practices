class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1 == s2) return true;
        int n = s1.size(), m = s2.size();
        if(n < m){ //make sure s1 > s2 in size
            swap(n, m);
            swap(s1, s2);
        }
        int i = 0, prefix = 0, suffix = m-1;
        while(i < n and prefix < m and s1[i] == s2[prefix]) i++, prefix++;
        if (prefix == m and s1[m] == ' ') return true;

        i = n-1;
        while(i > -1 and suffix > -1 and s1[i] == s2[suffix]) i--, suffix--;
        if (suffix == -1 and s1[i] == ' ') return true;
        
        for(int i = suffix+1; i < prefix; i++){
            if(s2[i] == ' ') return true;
        }
        return false;
    }
};
