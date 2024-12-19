class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int i = 0, give = 1;
        while(candies){
            if(i == num_people) i = 0;
            give = min(give, candies);
            res[i] += give;
            candies -= give;
            give++, i++;
        }
        return res;
    }
};
