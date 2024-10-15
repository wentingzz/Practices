class BetterSolution {
public:
    long long minimumSteps(string s) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        
        int n = s.size(), l = 0;
        while(l < n and s[l] == '0') l++;
        int r = l+1;
        long long res = 0;
        while(r < n){
            if(s[r] == '0'){
                res += r - l;
                swap(s[l++], s[r]);
            }
            r++;
        }
        return res;

    }
};
