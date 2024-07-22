class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};
        for(int& s: students) count[s]++;

        int res = sandwiches.size();
        for(int& s: sandwiches){
            if(count[s] > 0){
                count[s]--;
                res--;
            }else return res;
        }
        return res;
    }
};
