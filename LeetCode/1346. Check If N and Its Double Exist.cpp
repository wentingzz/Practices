class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> seen;
        for(int& a: arr){
            if(seen.find(2 * a) != seen.end()) return true;
            if(a % 2 == 0 and seen.find(a / 2) != seen.end()) return true;
            seen[a] = 1;
        }
        return false;
    }
};
