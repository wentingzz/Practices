class SpaceBetterSolution {
public:
    int commonPrefix(int num1, int num2) {
        // Convert both integers to strings
        string str1 = to_string(num1);
        string str2 = to_string(num2);
        
        // Find the common prefix length
        int i = 0;
        while (i < str1.size() && i < str2.size() && str1[i] == str2[i])  i++;
        
        if (i == 0)return -1; // No common prefix
        return i;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(), arr1.end(), [](const int& a, const int& b){
            return to_string(a) < to_string(b);
        });
        sort(arr2.begin(), arr2.end(), [](const int& a, const int& b){
            return to_string(a) < to_string(b);
        });
        // for(int& n: arr1) cout << n <<" ";
        // cout <<endl;
        int idx1 = 0, idx2 = 0, n = arr1.size(), m = arr2.size();
        int res = 0;
        while(idx1 < n and idx2 < m){
            res = max(res, commonPrefix(arr1[idx1], arr2[idx2]));
            if(to_string(arr1[idx1]) < to_string(arr2[idx2])) idx1++;
            else if(to_string(arr1[idx1]) > to_string(arr2[idx2])) idx2++;
            else idx1++, idx2++;
        }
        return res;
    }
};
