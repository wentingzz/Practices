class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), target = n * (n+1)/2;
        int freq[n+1];
        fill(freq, freq + n + 1, 0);
        int duplicate = 0;
        for(int& a: nums){
            target -= a;
            if(freq[a]++ > 0) duplicate = a;
        }

        return {duplicate, duplicate + target};
    }
};
