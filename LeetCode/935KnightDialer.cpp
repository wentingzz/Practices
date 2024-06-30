class Solution {
public:
//similar to 931
    int knightDialer(int n) {
        // Adjacency list for knight moves from each digit 
        vector<vector<int>> moves = {
            {4, 6},    // 4 and 6 can move to 0
            {6, 8},    // 1
            {7, 9},    // 2
            {4, 8},    // 3
            {0, 3, 9}, // 4
            {},        // 5
            {0, 1, 7}, // 6
            {2, 6},    // 7
            {1, 3},    // 8
            {2, 4}     // 9
        };

        // Array to track the number of distinct phone numbers ending in each digit
        int dp[10][2] = {0};

        // Initialize base case: for n=1, each digit has exactly one phone number
        for (int i = 0; i < 10; ++i) {
            dp[i][0] = 1;
        }

        const int MOD = 1000000007;

        // Iterate over the number of hops
        for (int step = 1; step < n; ++step) {
            int curr = step % 2;
            int prev = 1 - curr;

            // Reset the current state counts
            for (int digit = 0; digit < 10; ++digit) {
                dp[digit][curr] = 0;

                // Sum the counts from the previous state that can reach this digit
                for (int prevDigit : moves[digit]) {
                    dp[digit][curr] = (dp[digit][curr] + dp[prevDigit][prev]) % MOD;
                }
            }
        }

        int finalState = (n - 1) % 2;
        long long totalCombinations = 0;

        // Sum up all valid phone numbers of length n
        for (int i = 0; i < 10; ++i) {
            totalCombinations = (totalCombinations + dp[i][finalState]) % MOD;
        }

        return totalCombinations;
    }
};
