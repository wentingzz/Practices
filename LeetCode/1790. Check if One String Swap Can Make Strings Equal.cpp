class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 != n2) return false;
        int l = -1, r = -1;
        for(int i = 0; i < n1; i++){
            if(s1[i] != s2[i]){
                if(r != -1) return false;
                if(l == -1) l = i;
                else{
                    if(s1[l] != s2[i] or s1[i] != s2[l]) return false;
                    r = i;
                }
            }
        }
        return l == r or r > -1;
    }
};
