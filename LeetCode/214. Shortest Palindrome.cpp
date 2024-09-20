class SpaceEffectiveSolution {
public:
    int n;
    int numCharToAdd(string& s, int mid){
        int l = mid, r = mid;
        while(l >= 0 and r < n and s[l] == s[r]){
            l--;
            r++;
        }
        int res = l < 0 ? n-r : n;
        l = mid, r = mid+1;
        while(l >= 0 and r < n and s[l] == s[r]){
            l--;
            r++;
        }
        return min(res, (l < 0 ? n-r : n));
    }
    string shortestPalindrome(string s) {
        n = s.size();
        int start = n / 2, minLen = n;
        for(int i = start; i >= 0; i--){
            int tmp = numCharToAdd(s, i);
            if(minLen > tmp){
                minLen = tmp;
                break;
            }
        }
        string extra = s.substr(n-minLen);
        reverse(extra.begin(), extra.end());
        s = extra + s;
        return s;
    }
};
