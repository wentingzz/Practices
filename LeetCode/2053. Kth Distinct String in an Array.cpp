class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        for(string& s: arr){
            m[s]++;
        }
        int i = 0;
        for(string& s: arr){
            if(m[s] == 1) i++;
            if(i == k) return s;
        }
        return "";
    }
};
