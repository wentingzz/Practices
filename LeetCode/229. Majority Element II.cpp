class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int target = nums.size() / 3;
        for(int& n: nums){
            m[n]++;
        }
        vector<int> res;
        for(auto p: m){
            if(p.second > target)res.push_back(p.first);
        }
        return res;
    }
};

class SpaceBetterSolution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0, n1 = 0, n2 = 0;

        for(int& n: nums){
            //update counters
            if(n1 == n) c1++;
            else if(n2 == n) c2++;
            //get new candidtate
            else if(c1 == 0 and n1 != n) c1 = 1, n1 = n;
            else if(c2 == 0 and n2 != n) c2 = 1, n2 = n;
            //update counter
            else{
                c1--;
                c2--;
            }
        }
        c1 = 0, c2 = 0;
        int target = nums.size() / 3;
        for(int& n: nums){
            if(n == n1) c1++;
            if(n == n2) c2++;
        }
        vector<int> res;
        if(c1 > target) res.push_back(n1);
        if(n1 != n2 and c2 > target) res.push_back(n2);
        return res;
    }
};
