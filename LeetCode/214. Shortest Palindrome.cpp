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

// the following code is copied form https://leetcode.com/problems/shortest-palindrome/submissions/1396477603/?envType=daily-question&envId=2024-09-20
class TimeEffectiveSolution {
public:
    string shortestPalindrome(string s) {
        int count = kmp(string(s.rbegin(), s.rend()), s);
        return string(s.rbegin(), s.rend()).substr(0, s.length() - count) + s;
    }

private:
    int kmp(const string &txt, const string &patt) {
        string newString = patt + '#' + txt;
        vector<int> pi(newString.length(), 0);
        int i = 1, k = 0;
        while (i < newString.length()) {
            if (newString[i] == newString[k]) {
                k++;
                pi[i] = k;
                i++;
            } else {
                if (k > 0) {
                    k = pi[k - 1];
                } else {
                    pi[i] = 0;
                    i++;
                }
            }
        }
        return pi.back();
    }
};
