class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(string& o: operations){
            if(o == "--X" or o == "X--") res--;
            else res++;
        }
        return res;
    }
};
