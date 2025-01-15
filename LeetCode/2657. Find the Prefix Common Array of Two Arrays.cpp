class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> seen(n+1, 0);
        vector<int> res(n, 0);
        int prev = 0;
        for(int i = 0; i < n; i++){
            seen[B[i]]++, seen[A[i]]++;
            res[i] = prev + (seen[B[i]] == 2) + (seen[A[i]] == 2) - (A[i] == B[i]);
            prev = res[i];
        }
        return res;
    }
};
